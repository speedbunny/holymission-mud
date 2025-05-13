#include <lw.h>

mapping mFates;

void setFate(string sInitiater,string sAct,string sTarget,string sFun) {
    if(!mFates)
        mFates=([]);
    if(!mFates[sInitiater])
        mFates[sInitiater]=([]);
    if(!mFates[sInitiater][sAct])
        mFates[sInitiater][sAct]=([]);
    if(!mFates[sInitiater][sAct][sTarget])
        mFates[sInitiater][sAct][sTarget]=({});
    mFates[sInitiater][sAct][sTarget]+=({sFun});
}

string *queryFateActs(string sInitiater) {
    if(mFates && mFates[sInitiater])
        return m_indices(mFates[sInitiater]);
}

varargs int triggerFate(object oTp,string sAct,string *saInfo) {
     string sInitiater,sTarget,sFun,*saTargets,*saFuns;
     int iSz;
     mapping mMap1,mMap2;

    sInitiater=explode("/"+file_name(previous_object()),"#")[0];
    if(!mFates || !mFates[sInitiater])
        return 0;
    else
        mMap1=mFates[sInitiater];
    if(!mMap1[sAct])
        return 0;
    else {
        mMap2=mMap1[sAct];
        iSz=m_sizeof(mMap2);
    }
    if(!iSz)
        return 0;
    else {
        saTargets=m_indices(mMap2);
        sTarget=saTargets[random(iSz)];
        saFuns=mMap2[sTarget];
        sFun=saFuns[random(sizeof(saFuns))];
        call_other(sTarget,sFun,oTp,sAct,saInfo);
        return 1;
    }
}

int _test(string sStr) {
    string sAct,sArg,sFun,sRet,sTarget,*saIni,*saActs,*saTargets,*saFuns;
    int i;

    if(!sStr || sStr=="")
        return 0;
    if(sscanf(sStr,"%s %s",sAct,sArg)!=2)
        sAct=sStr;

    sRet="";
    saIni=m_indices(mFates);
    for(i=0;i<sizeof(saIni);i++) {
        saActs=queryFateActs(saIni[i]);
        if(member_array(sAct,saActs)!=-1) {
            sRet=sprintf("%s%sMatched a fate act in '%s' for act '%s'.\n",
                         sRet,(sRet==""?"":"\n"),saIni[i],sAct);
            saTargets=m_indices(mFates[saIni[i]][sAct]);
            sTarget=saTargets[random(sizeof(saTargets))];
            saFuns=mFates[saIni[i]][sAct][sTarget];
            sFun=saFuns[random(sizeof(saFuns))];
            sRet=sprintf("%sI would call '%s' in '%s' with args '%O', \
'%s'%s\n",
                         sRet,sFun,sTarget,this_player(),sAct,
                         (sArg?" and extra info '"+sArg+"'":""));
        }
    }
    if(sRet=="")
      sRet="No match.\n";
    this_player()->more_string(lw(sRet));
    return 1;
}

void init() {
    add_action("_test","test");
}
