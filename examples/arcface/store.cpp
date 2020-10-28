#include "store.h"


Store ::Store(const char *file, Mode mode) {
      filename = file;
      if (mode == WRITE ) {
          inout.open(filename, ios::out|ios::app|ios::binary);
      }else {
          inout.open(filename, ios::in|ios::binary);
      }
}

void Store::flush(void){
    inout.close();
}

int Store::dump(vector<FaceFeature> &gFeatures){
    for (auto it = gFeatures.begin(); it !=gFeatures.end(); it++)
    {
        /*
        inout << (*it).name<<endl;
        for (int i  = 0; i< 128; i++)
            inout<<(*it).feature[i]<<endl;
        */
        inout.write((char *)&(*it), sizeof(FaceFeature));
    }

}
int Store::load(vector<FaceFeature> &gFeatures){
    /*
    while (!inout.eof()) {
        FaceFeature tmp;
        inout >> tmp.name;
        for (int i  = 0; i< 128; i++)
            inout>>tmp.feature[i];
        gFeatures.push_back(tmp);
    }
   */
    while (!inout.eof()) {
        FaceFeature tmp;
        inout.read((char *)&tmp, sizeof(FaceFeature));
        int i = inout.gcount();
        if (i != sizeof(FaceFeature))
            break;
        gFeatures.push_back(tmp);
    }
}

Store ::~Store() {
    inout.close();
}
/*
int main(){
    vector<FaceFeature> gFeatures;
    FaceFeature temp = {"xiechc", {-0.0498137,0.0589042,-0.0376527,-0.101112,0.0313071,-0.120467,0.0572538,0.117286,-0.144796,-0.059148,-0.0387299,-0.0289869,-0.097654,0.0580597,-0.0322316,-0.0404122,0.0251413,0.130723,-0.139564,0.018043,-0.0190816,-0.0309694,0.0827146,-0.107912,-0.0652341,0.0587806,0.0710347,0.0147295,0.164604,-0.089224,0.0777105,0.0262255,0.0904136,0.0058277,-0.0402637,-0.0594295,-0.00742405,0.112926,-0.00792374,0.120283,-0.0935432,-0.00924759,-0.0936701,0.0714524,0.0781352,0.0208245,-0.00539935,-0.12245,0.0324269,-0.0326275,0.0288401,-0.0604426,0.192122,-0.0642601,-0.046798,-0.019437,-0.0115649,-0.0012037,0.0338915,0.0641501,-0.018096,-0.015274,-0.0361472,-0.107832,-0.0452146,-0.0765692,-0.017775,0.0256729,0.0202204,-0.0548856,0.121113,0.151799,-0.0835365,0.0957524,0.102367,-0.15924,-0.124827,-0.0517728,-0.0159528,-0.0266019,0.065653,-0.148715,-0.0849086,-0.0583458,-0.0474751,-0.0593391,0.158633,-0.249781,0.00214009,0.0226717,-0.109876,-0.130074,-0.102824,0.061604,-0.19601,-0.128129,-0.0798265,0.105964,-0.0144881,0.0807251,0.136085,0.111599,0.0891687,0.097816,0.0805367,0.181766,0.0799179,0.134738,-0.077369,0.0449693,0.0492594,0.0243305,-0.0887662,-0.0570394,-0.142709,0.102117,-0.21697,0.0588492,0.0328538,-0.0169873,0.0808643,0.0160196,0.00591027,-0.130699,-0.0316537,0.0565128,0.137584,0.0472695}};
    gFeatures.push_back(temp);
    gFeatures.push_back(temp);

    Store a("3", WRITE);
    a.dump(gFeatures);
    a.flush();

    Store b("3", READ);
    vector<FaceFeature> grFeatures;
    b.load(grFeatures);
    int i = 3;
}
*/
