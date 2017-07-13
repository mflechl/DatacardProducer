import ROOT
import copy
import sys
import os
import math
from array import array

ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(0)

def main():

    X = {'jeta_1':'eta_{j1}',
         'jeta_2':'eta_{j2}',
         'met':'MET',
         'pt_1':'p_{T,j1}',
         'pt_2':'p_{T,j2}',
         'm_vis':'m_{vis}',
         'mt_1':'m_T',
         'mttot':'m_{TOT}',
         'mjj':'m_{jj}',
         'jeta1eta2':'#eta_{1,2}',
         'jdeta':'#Delta #eta'
        }

    for i,pl_var in enumerate( X.keys() ):
        t ="tight"
        root_file = t + '_htt_et.inputs-mssm-13TeV-'+pl_var+'.root'
        if not os.path.exists(root_file): continue
        tmp = ROOT.TFile(root_file)

        for key in tmp.GetListOfKeys():
            folder = key.GetTitle()
            print root_file, folder
            histo_names = ['{0}/ZL'.format(folder),
                           '{0}/ZTT'.format(folder),
                           '{0}/EWKZ'.format(folder),
                           '{0}/jetFakes'.format(folder),
                           '{0}/TTT'.format(folder),
                           '{0}/VVT'.format(folder)]

            signal = ['{0}/ggH90'.format(folder),
                      '{0}/ggH700'.format(folder),
                      '{0}/ggH1500'.format(folder)
                     ]

                         

            titles = ['ZL',
                      'ZTT',
                      'EWKZ',
                      'jetFakes',
                      'TTT',
                      'VVT',
                      'ggH90',
                      'ggH700',
                      'ggH1500']

            display = DisplayManager(outname = t+"_"+pl_var + '_' + folder.replace("mt_",""),
                                     datatype = 'png',
                                     ratio = True,
                                     Title_X = X[pl_var],
                                     InfoLeft = "#mu#tau "+folder.replace("mt_",""),
                                     InfoRight = "35.9 fb^{-1} (13 TeV)")


            display.SetData(root_file, '{0}/data_obs'.format(folder))

            display.getHistos(root_file, histo_names)
            display.stackHistos()
            #display.addSignal(root_file, signal)
            display.AddCMS = True
            display.AddInfoLeft = True
            display.AddInfoRight = True
            display.titles = titles

            display.Draw()



def createRatioCanvas(name, errorBandFillColor=14, errorBandStyle=3354):
    cv = ROOT.TCanvas(name, name, 10, 10, 800, 600)
    # this is the tricky part...
    # Divide with correct margins
    cv.Divide(1, 2, 0.0, 0.0)

    # Set Pad sizes
    cv.GetPad(1).SetPad(0.0, 0.32, 1., 1.0)
    cv.GetPad(2).SetPad(0.0, 0.00, 1., 0.34)

    cv.GetPad(1).SetFillStyle(4000)
    cv.GetPad(2).SetFillStyle(4000)

    # Set pad margins 1
    cv.cd(1)
    ROOT.gPad.SetTopMargin(0.08)
    ROOT.gPad.SetLeftMargin(0.12)
    ROOT.gPad.SetBottomMargin(0.03)
    ROOT.gPad.SetRightMargin(0.2)
    ROOT.gPad.SetLogy(True)

    # Set pad margins 2
    cv.cd(2)
    ROOT.gPad.SetBottomMargin(0.35)
    ROOT.gPad.SetLeftMargin(0.12)
    ROOT.gPad.SetRightMargin(0.2)
    ROOT.gPad.SetGridy()

    bogyHist = ROOT.TH1F("legendPseudoHist", "", 1, 1., 2.)
    bogyHist.SetFillColor(errorBandFillColor)
    bogyHist.SetFillStyle(errorBandStyle)
    bogyHist.SetLineColor(0)

    cv.cd(1)
    return cv


class DisplayManager(object):

    def __init__(self,outname = 'out',
                      datatype = 'png',
                      ratio = True,
                      Title_X = "#eta_{j1} [GeV]",
                      InfoLeft = "#mu#tau inclusive",
                      InfoRight = "12.9 fb^{-1} (13 TeV)"):

        if ratio:
            self.canvas = createRatioCanvas(outname)
        else:
            self.canvas = ROOT.TCanvas(outname)

        self.name = outname
        self.datatype = datatype
        self.draw_ratio = ratio
        self.histos = []
        self.titles = []
        self.Title_X = Title_X
        self.Title_Y = "Events"
        self.data = None
        self.AddCMS = True
        self.AddInfoRight = True
        self.AddInfoLeft = True
        self.InfoLeft = InfoLeft
        self.InfoRight = InfoRight
        self.errorHist = None
        self.signal = []
        if ratio:
            self.Legend = ROOT.TLegend(0.8, 0.52, 1., 0.92)
        else:
            self.Legend = ROOT.TLegend(0.73, 0.54, 0.98, 0.9)

        self.applyLegendSettings(self.Legend)

        self.draw_ratioLegend = ROOT.TLegend(0.15, 0.79, 0.5, 0.89)
        self.applyLegendSettings(self.draw_ratioLegend)

        self.pullRange = 0.5
    def applyLegendSettings(self,leg):
        leg.SetBorderSize(0)
        leg.SetFillColor(10)
        leg.SetLineWidth(0)
        leg.SetFillStyle(0)
        if self.draw_ratio:
            leg.SetTextSize(0.04)
        else:
            leg.SetTextSize(0.035)
        leg.SetTextFont(12)

    def getHistos(self,root_file ,histo_names):
        histos = []
        f0 = ROOT.TFile(root_file)
        for name in histo_names:
            tmp = copy.deepcopy( f0.Get(name) )
            try:
                if 'TH1' in tmp.ClassName():
                    histos.append(tmp)
            except ReferenceError:
                print "{0} does not exist".format(name)
                sys.exit()

        f0.Close()
        self.histos = histos
        return histos

    def applySystematics(self,systList):
        for i, syst in enumerate(systList):
            if syst == 0.: continue
            for j in xrange(self.histos[i].GetNbinsX()+1):
                self.histos[i].SetBinError(j, math.sqrt( self.histos[i].GetBinError(j)**2 + syst**2))


    def SetData(self,root_file, name):
        f0 = ROOT.TFile(root_file)
        h = copy.deepcopy( f0.Get(name) )
        if "mttot" in root_file:
            for i in xrange(h.GetNbinsX()+1):
                if h.GetBinLowEdge(i+1) > 100:
                    h.SetBinContent(i, 0.0001)
        f0.Close()
        self.data = h


    def applyHistStyle(self, h, i):
        colours = [ROOT.kRed+1,
                   ROOT.kBlue+1,
                   ROOT.kYellow+1,
                   ROOT.kMagenta+1,
                   ROOT.kGreen+1,
                   ROOT.kCyan+1,
                   ROOT.kOrange+1,
                   ROOT.kPink+1,
                   ROOT.kAzure+1]

        h.SetLineColor(1)
        h.SetLineWidth(1)
        h.SetFillColor(colours[i])
        h.SetStats(False)
        h.GetYaxis().SetTitle(self.Title_Y)
        h.GetXaxis().SetTitle(self.Title_X)
        h.GetYaxis().SetTitleOffset(1.4);

    def applySigStyle(self, h, i):
        colours = [ROOT.kRed+1,
                   ROOT.kBlue+1,
                   ROOT.kYellow+1,
                   ROOT.kMagenta+1,
                   ROOT.kGreen+1,
                   ROOT.kCyan+1,
                   ROOT.kOrange+1,
                   ROOT.kPink+1,
                   ROOT.kAzure+1]

        h.SetLineColor(colours[i])
        h.SetLineWidth(2)
        #h.SetFillColor(colours[i])
        h.SetStats(False)
        h.GetYaxis().SetTitle(self.Title_Y)
        h.GetXaxis().SetTitle(self.Title_X)
        h.GetYaxis().SetTitleOffset(1.4);

    def applyDataStyle(self, h):
        h.SetLineColor(1)
        h.SetMarkerStyle(8)
        h.SetMarkerSize(0.8)
        h.SetLineWidth(0)
        h.SetStats(False)
        h.GetYaxis().SetTitle(self.Title_Y)
        h.GetXaxis().SetTitle(self.Title_X)
        h.GetYaxis().SetTitleOffset(1.4);

    def stackHistos(self):
        newHistos = []
        for i,h1 in enumerate(self.histos):
            newHistos.append(h1)
            for j, h2 in enumerate(self.histos):
                if j > i:
                    newHistos[i].Add(h2)
        self.histos = newHistos

    def addSignal(self,root_file ,histo_names):
        histos = []
        f0 = ROOT.TFile(root_file)
        for name in histo_names:

            tmp = copy.deepcopy( f0.Get(name) )
            try:
                if 'TH1' in tmp.ClassName():
                    histos.append(tmp)
            except ReferenceError:
                print "{0} does not exist".format(name)
                #sys.exit()

        f0.Close()
        self.signal = histos


    def getErrorHist(self):

        arr = []
        nmin = self.histos[0].GetBinLowEdge(0)
        bins = self.histos[0].GetNbinsX()+1
        for i in xrange(1,bins):

            arr.append(self.histos[0].GetBinLowEdge(i-1))

        arr.sort()
        nmax = self.histos[0].GetBinLowEdge(bins)

        self.errorHist = ROOT.TH1F('uncertain','',len(arr)-1,array('d',arr))
        for i in xrange(1,bins):

                self.errorHist.SetBinContent( i+1, self.histos[0].GetBinContent(i) )
                self.errorHist.SetBinError( i+1, self.histos[0].GetBinError(i) )



        self.errorHist.SetFillColor(ROOT.kBlack)
        self.errorHist.SetFillStyle(3013)

    def getErrorRatioHist(self):

        nmin = self.histos[0].GetBinLowEdge(0)
        bins = self.histos[0].GetNbinsX()+1

        nmax = self.histos[0].GetBinLowEdge(bins)

        self.errorRatioHist = ROOT.TH1F('uncertainRatio','',bins, nmin, nmax)
        for i in xrange(1,bins):

            if self.histos[0].GetBinContent(i) < 1e-8:
                self.errorRatioHist.SetBinContent( i+1, 0 )
                self.errorRatioHist.SetBinError( i+1, 0 )
            else:
                self.errorRatioHist.SetBinContent( i+1, 1 )
                self.errorRatioHist.SetBinError( i+1, self.histos[0].GetBinError(i) / self.histos[0].GetBinContent(i) )


        self.errorRatioHist.SetFillColor(ROOT.kBlack)
        self.errorRatioHist.SetFillStyle(3013)



    def Draw(self, xmax=None):

        ymax = self.data.GetMaximum()*10
        if self.AddCMS:
            
            if self.draw_ratio:
                ymax *= 1.3
                cms1 = ROOT.TLatex( 0.17, 0.85, "CMS" )
                cms2 = ROOT.TLatex( 0.17, 0.8, "OwnWork" )
            else:
                ymax *= 1.2
                cms1 = ROOT.TLatex( 0.15, 0.84, "CMS" )
                cms2 = ROOT.TLatex( 0.15, 0.80, "OwnWork" )
            cms1.SetNDC();
            cms1.SetTextSize(0.055);            
            cms2.SetNDC();
            cms2.SetTextFont(12)
            cms2.SetTextSize(0.04);
        else:
            ymax *= 1.05
            

        self.Legend.Clear()
        self.draw_ratioLegend.Clear()
        self.applyDataStyle(self.data)
        self.Legend.AddEntry(self.data, 'data')

        self.getErrorHist()
        
        for i, h in enumerate(self.histos + self.signal):
            if h in self.histos: self.applyHistStyle(h,i)
            if h in self.signal: self.applySigStyle(h,i)

            title = self.titles[i]
            h.GetYaxis().SetRangeUser(0.1, ymax)
            if xmax:
                h.GetXaxis().SetRangeUser(0., xmax)
            self.Legend.AddEntry(h, title ,'f')
            if i ==0:
                h.Draw('HIST')
                if self.AddCMS:
                    cms1.Draw()
                    cms2.Draw()
                if self.AddInfoRight:
                    if not self.draw_ratio:
                        infoRight = ROOT.TLatex( 0.63, 0.91, self.InfoRight )
                    else:
                        infoRight = ROOT.TLatex( 0.65, 0.93, self.InfoRight )
                    infoRight.SetNDC();
                    infoRight.SetTextSize(0.035);
                    infoRight.Draw()

                if self.AddInfoLeft:
                    if self.draw_ratio:
                        infoLeft = ROOT.TLatex( 0.12, 0.94, self.InfoLeft )
                        infoLeft.SetTextSize(0.055);
                    else:
                        infoLeft = ROOT.TLatex( 0.10, 0.92, self.InfoLeft )
                        infoLeft.SetTextSize(0.045);

                    infoLeft.SetNDC();
                    
                    infoLeft.Draw()

            else:
                h.Draw('SAME HIST')

            
        self.errorHist.Draw("same E2")
        self.data.Draw('SAME E')
        self.Legend.Draw()


        if self.draw_ratio:
            self.canvas.cd(2)


            histPull = copy.deepcopy(self.data)
            histPull.Divide(self.histos[0])
            histPull.UseCurrentStyle()


            histPull.SetLineColor(self.data.GetLineColor())
            histPull.SetMarkerColor(self.data.GetLineColor())
            histPull.SetMarkerStyle(self.data.GetMarkerStyle())
            histPull.SetMarkerSize(self.data.GetMarkerSize())
            histPull.SetLineStyle(self.data.GetLineStyle())
            histPull.SetLineWidth(self.data.GetLineWidth())
     
            histPull.GetYaxis().SetRangeUser(-self.pullRange + 1., self.pullRange + 1.)
            

            # defaultYtoPixel = 408.  # height in pixels of default canvas
            defaultYtoPixel = self.canvas.GetPad(1).YtoPixel(0.)
            pad2YtoPixel = float(self.canvas.GetPad(2).YtoPixel(0))
            pad2XaxisFactor = defaultYtoPixel / pad2YtoPixel

            histPull.GetXaxis().SetLabelSize(self.data.GetXaxis().GetLabelSize()*pad2XaxisFactor)
            histPull.GetXaxis().SetLabelOffset(self.data.GetXaxis().GetLabelOffset()*pad2XaxisFactor)
            histPull.GetXaxis().SetTitleSize(self.data.GetXaxis().GetTitleSize()*pad2XaxisFactor)
            histPull.GetXaxis().SetTitleOffset(self.data.GetXaxis().GetTitleOffset()/pad2XaxisFactor*2.5)

            histPull.GetYaxis().SetLabelSize(self.data.GetYaxis().GetLabelSize()*pad2XaxisFactor)
            histPull.GetYaxis().SetLabelOffset(self.data.GetYaxis().GetLabelOffset()*pad2XaxisFactor)
            histPull.GetYaxis().SetTitleSize(self.data.GetYaxis().GetTitleSize()*pad2XaxisFactor)
            histPull.GetYaxis().SetTitleOffset(self.data.GetYaxis().GetTitleOffset()/pad2XaxisFactor)

            histPull.GetYaxis().CenterTitle()
            histPull.GetXaxis().SetTickLength(histPull.GetXaxis().GetTickLength()*pad2XaxisFactor)
            histPull.GetYaxis().SetNdivisions(306)

            histPull.GetYaxis().SetTitle("Data/MC Ratio")
            histPull.SetTitle('')
            histPull.Draw("e")
            self.getErrorRatioHist()
            self.errorRatioHist.Draw("same E2")

            self.draw_ratioLegend.AddEntry(histPull, "MC")


#            self.draw_ratioLegend.Draw()

            # This is a little bit ugly though ...

            for i, h in enumerate(self.histos):
                h.GetXaxis().SetLabelSize(0)

            self.canvas.cd(1)

        self.canvas.Update()
        #self.canvas.SetLogy(True)
        self.canvas.Print( '.'.join([self.name, self.datatype]))

if __name__ == '__main__':
    main()
