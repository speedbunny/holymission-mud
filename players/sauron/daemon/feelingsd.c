// Key for symbols in feeling strings:
//	$Ns = Name of subject.
//	$Nv = Name of victim. ("yourself"/POSS+"self" if victim==subject)
//	$Os = Objective applied to the subject.
//	$Ov = Objective applied to the victim.
//	$Ps = Possessive applied to the subject.
//	$Pv = Possessive applied to the victim.
//	$Qs = Possessive name applied to the subject (<name>'s).
//	$Qv = Possessive name applied to the victim (<name>'s).
//	$Rs = Pronoun applied to the subject.
//	$Rv = Pronoun applied to the victim.
//	$S  = Make the text up to the next space visible to the subject
//            only.
//	$T  = Make the text up to the next space visible to the target
//            only.
//	$U  = Make the text up to the next space visible to the 'others'
//            only.
//	$V  = Verb.
//	$A  = Adverb.
//	$s  = Add an 's' to the preceeding work (except for the msg sent
//            to the subject).

#include <adverbs.h>
#include <sys_defs.h>

#define FEELINGS	"/players/sauron/data/feelings/"
#define SIMPLE		0
#define TARGET		1
#define ADVERB		2

private mapping mFeelings,mAdverbs;

string substitute(string sStr,string sMatch,string sRep) {
    if(sStr && sMatch && sRep)
        return implode(explode(sStr,sMatch),sRep);
}

string pluraliseVerb(string sVerb) {
    return lower_case(INVENTORYD->pluralise(sVerb,1));
}

void initAdverbs() {
    if(!mAdverbs) {
        mAdverbs=([]);
        mAdverbs['a']=ADVERBS_A;
        mAdverbs['b']=ADVERBS_B;
        mAdverbs['c']=ADVERBS_C;
        mAdverbs['d']=ADVERBS_D;
        mAdverbs['e']=ADVERBS_E;
        mAdverbs['f']=ADVERBS_F;
        mAdverbs['g']=ADVERBS_G;
        mAdverbs['h']=ADVERBS_H;
        mAdverbs['i']=ADVERBS_I;
        mAdverbs['j']=ADVERBS_J;
        mAdverbs['k']=ADVERBS_K;
        mAdverbs['l']=ADVERBS_L;
        mAdverbs['m']=ADVERBS_M;
        mAdverbs['n']=ADVERBS_N;
        mAdverbs['o']=ADVERBS_O;
        mAdverbs['p']=ADVERBS_P;
        mAdverbs['q']=ADVERBS_Q;
        mAdverbs['r']=ADVERBS_R;
        mAdverbs['s']=ADVERBS_S;
        mAdverbs['t']=ADVERBS_T;
        mAdverbs['u']=ADVERBS_U;
        mAdverbs['v']=ADVERBS_V;
        mAdverbs['w']=ADVERBS_W;
        mAdverbs['x']=ADVERBS_X;
        mAdverbs['y']=ADVERBS_Y;
        mAdverbs['z']=ADVERBS_Z;
    }
}

void initFeelings() {
    string *saDir;
    int i;

    if(!mFeelings) {
        saDir=get_dir(FEELINGS+".");
        mFeelings=([]);
        for(i=0;i<sizeof(saDir);i++) {
            if(saDir[i][<2..<1] == ".c") {
                saDir[i] = saDir[i][0..<3];
                mFeelings[saDir[i]] = FEELINGS+saDir[i];
            }
        }
    }
}

varargs string *allAdverbs(string sStr) {
    string *saTmp;
    int i;

    initAdverbs();
    if(sStr && sStr!="")
        return mAdverbs[sStr[0]]; 
    else {
        saTmp=({});
        for(i='a';i<='z';i++)
            saTmp+=mAdverbs[i];
        return saTmp;
    }
}

string *allFeelings() {
    initFeelings();
    return m_indices(mFeelings);
}

string validAdverb(string sMatch) {
    string *saAdverbs,*saTmp;
    int i,iLen,iSz;

    initAdverbs();
    if(!sMatch || sMatch=="")
        return 0;
    else
        iLen=strlen(sMatch)-1;
    saAdverbs=mAdverbs[sMatch[0]];
    saTmp=({});
    i=0;
    iSz=sizeof(saAdverbs);
    for(i=0;i<iSz;i++) {
        if(saAdverbs[i][0..iLen]==sMatch)
            saTmp+=({saAdverbs[i]});
    }
    if(sizeof(saTmp)==1)
        return saTmp[0];
    else if(sizeof(saTmp))
        printf("The adverb \"%s\" is ambiguous (\"%s\"). Please be more \
precise.\n",
               sMatch,listArray(saTmp,1));
    else
        printf("No adverb found to match '%s'.\n",sMatch);
}

varargs mixed validFeeling(string sMatch,int iFlag) {
    string *saFeelings,*saTmp;
    int i,iLen,iSz;

    initFeelings();
    saFeelings=allFeelings();
    if(!sMatch || sMatch=="")
        return 0;
    else
        iLen=strlen(sMatch)-1;
    saTmp=({});
    i=0;
    iSz=sizeof(saFeelings);
    for(i=0;i<iSz;i++) {
        if(saFeelings[i][0..iLen]==sMatch)
            saTmp+=({saFeelings[i]});
    }
    if(iFlag)
        return saTmp;
    else if(sizeof(saTmp)==1)
        return saTmp[0];
    else if(sizeof(saTmp))
        printf("The feeling \"%s\" is ambiguous (\"%s\"). Please be more \
precise.\n",
               sMatch,listArray(saTmp,1));

#ifdef DEBUG
    else
        printf("No feeling found to match '%s'.\n",sMatch);
#endif // DEBUG

}

string validRemoteFeeling(string sMatch) {
    string *saTmp;
    if(sMatch && strlen(sMatch)>1 && sMatch[0..0]=="r") {
        saTmp=validFeeling(sMatch[1..<1],1);
        if(sizeof(saTmp)==1)
            return "r"+saTmp[0];
        else if(sizeof(saTmp))
            printf("The remote feeling \"%s\" is ambiguous (\"%s\"). Please \
be more precise.\n",
                   sMatch,listArray(saTmp,1));

#ifdef DEBUG
        else
            printf("No remote feeling found to match '%s'.\n",sMatch);
#endif // DEBUG

    }
}

varargs string *parseFeeling(string sVerb,object oTarget,string sAdverb,
                             int iRemote) {
    string *saRet,*saTmp,sTmp,sRet;
    int iTmp,iTmp2;
    object oSubject;

    oSubject=this_player();
    saRet=allocate(3);
    if(sVerb) {
        saTmp=mFeelings[sVerb]->feelingInfo();
        if(oTarget) {
            sRet=saTmp[TARGET];
            if(!sRet) {
                sRet=saTmp[SIMPLE];
                oTarget=(object)0;
            }
        }
        else {
            sRet=saTmp[SIMPLE];
            if(!sRet || iRemote == 1) {
                printf("The feeling '%s%s' requires a target.\n",
                       iRemote==1?"r":"",sVerb);
                return saRet;
            }
        }
        if(!sAdverb && saTmp[ADVERB])
            sAdverb=saTmp[ADVERB];

        saRet[0]=sRet;
        if(iRemote==1)
            saRet[0]=substitute(saRet[0],"$Ns","you");
        else
            saRet[0]=substitute(saRet[0],"$Ns","You");
        saRet[0]=substitute(saRet[0],"$Os","you");
        saRet[0]=substitute(saRet[0],"$Ps","your");
        if(oTarget) {
            if(oTarget==oSubject) {
                saRet[0]=substitute(saRet[0],"$Nv","yourself");
                saRet[0]=substitute(saRet[0],"$Ov","you");
                saRet[0]=substitute(saRet[0],"$Pv","your own");
                saRet[0]=substitute(saRet[0],"$Qv","your own");
            }
            else {
                sTmp=oTarget->query_name_true();
                saRet[0]=substitute(saRet[0],"$Nv",sTmp);
                saRet[0]=substitute(saRet[0],"$Ov",
                                    oTarget->query_objective());
                saRet[0]=substitute(saRet[0],"$Pv",
                                    oTarget->query_possessive());
                saRet[0]=substitute(saRet[0],"$Qv",
                                    sTmp+(sTmp[<1..<1]=="s"?
                                              "'":
                                              "'s"));
            }
        }
        saRet[0]=substitute(saRet[0],"$S","");
        while((iTmp=strstr(saRet[0],"$T"))>=0) {
            iTmp2=strstr(saRet[0],"$T",iTmp+2);
            if(iTmp2==-1)
                iTmp2=strlen(saRet[0])-2;
            if(iTmp==0)
                saRet[0]=saRet[0][iTmp2+2..<1];
            else if(iTmp2==strlen(saRet[0])-2)
                saRet[0]=saRet[0][0..iTmp-1];
            else
                saRet[0]=saRet[0][0..iTmp-1]+saRet[0][iTmp2+2..<1];
        }
        while((iTmp=strstr(saRet[0],"$U"))>=0) {
            iTmp2=strstr(saRet[0],"$U",iTmp+2);
            if(iTmp2==-1)
                iTmp2=strlen(saRet[0])-2;
            if(iTmp==0)
                saRet[0]=saRet[0][iTmp2+2..<1];
            else if(iTmp2==strlen(saRet[0])-2)
                saRet[0]=saRet[0][0..iTmp-1];
            else
                saRet[0]=saRet[0][0..iTmp-1]+saRet[0][iTmp2+2..<1];
        }
        saRet[0]=substitute(saRet[0],"$V",sVerb);
        saTmp = explode(saRet[0], "$A");
        if(sizeof(saTmp) == 2) {
            if(sAdverb)
                saRet[0] = implode(saTmp, sAdverb);
            else
                saRet[0] = saTmp[0][0..<2]+saTmp[1];
        }
        saRet[0]=substitute(saRet[0],"$s","");
            
        if(oTarget && oTarget!=oSubject) {
            saRet[1]=sRet;
            if(oSubject->is_invis_for(oTarget))
                saRet[1]=substitute(saRet[1],"$Ns","Someone");
            else
                saRet[1]=substitute(saRet[1],"$Ns",oSubject->query_name_true());
            saRet[1]=substitute(saRet[1],"$Os",oSubject->query_objective());
            saRet[1]=substitute(saRet[1],"$Ps",oSubject->query_possessive());
            saRet[1]=substitute(saRet[1],"$Nv","you");
            saRet[1]=substitute(saRet[1],"$Ov","you");
            saRet[1]=substitute(saRet[1],"$Pv","your");
            saRet[1]=substitute(saRet[1],"$Qv","your");
            while((iTmp=strstr(saRet[1],"$S"))>=0) {
                iTmp2=strstr(saRet[1],"$S",iTmp+2);
                if(iTmp2==-1)
                    iTmp2=strlen(saRet[1])-2;
                if(iTmp==0)
                    saRet[1]=saRet[1][iTmp2+2..<1];
                else if(iTmp2==strlen(saRet[1])-2)
                    saRet[1]=saRet[1][0..iTmp-1];
                else
                    saRet[1]=saRet[1][0..iTmp-1]+saRet[1][iTmp2+2..<1];
            }
            saRet[1]=substitute(saRet[1],"$T","");
            while((iTmp=strstr(saRet[1],"$U"))>=0) {
                iTmp2=strstr(saRet[1],"$U",iTmp+2);
                if(iTmp2==-1)
                    iTmp2=strlen(saRet[1])-2;
                if(iTmp==0)
                    saRet[1]=saRet[1][iTmp2+2..<1];
                else if(iTmp2==strlen(saRet[1])-2)
                    saRet[1]=saRet[1][0..iTmp-1];
                else
                    saRet[1]=saRet[1][0..iTmp-1]+saRet[1][iTmp2+2..<1];
            }
            saRet[1]=substitute(saRet[1],"$V",pluraliseVerb(sVerb));
            saTmp = explode(saRet[1], "$A");
            if(sizeof(saTmp) == 2) {
                if(sAdverb)  
                    saRet[1] = implode(saTmp, sAdverb);
                else 
                    saRet[1] = saTmp[0][0..<2]+saTmp[1];
            }
            saRet[1]=substitute(saRet[1],"$s","s");
        }

        if(iRemote!=1) {
            saRet[2]=sRet;
            saRet[2]=substitute(saRet[2],"$Ns",
                                (iRemote?
                                     oSubject->query_real_name(1):
                                     oSubject->query_name()));
            saRet[2]=substitute(saRet[2],"$Os",oSubject->query_objective());
            saRet[2]=substitute(saRet[2],"$Ps",oSubject->query_possessive());
            if(oTarget) {
                if(oTarget==oSubject) {
                    saRet[2]=substitute(saRet[2],"$Nv",
                                        oSubject->query_objective()+"self");
                    saRet[2]=substitute(saRet[2],"$Ov",
                                        oSubject->query_objective());
                    saRet[2]=substitute(saRet[2],"$Pv",
                                        oSubject->query_possessive()+" own");
                    saRet[2]=substitute(saRet[2],"$Qv",
                                        oSubject->query_possessive()+" own");
                }
                else {
                    if(iRemote)
                        sTmp=oTarget->query_real_name(1);
                    else
                        sTmp=oTarget->query_name();
                    saRet[2]=substitute(saRet[2],"$Nv",sTmp);
                    saRet[2]=substitute(saRet[2],"$Ov",sTmp);
                    saRet[2]=substitute(saRet[2],"$Pv",
                                        oTarget->query_possessive());
                    saRet[2]=substitute(saRet[2],"$Qv",
                                        sTmp+(sTmp[<1..<1]=="s"?
                                                  "'":
                                                  "'s"));
                }
            }
            while((iTmp=strstr(saRet[2],"$S"))>=0) {
                iTmp2=strstr(saRet[2],"$S",iTmp+2);
                if(iTmp2==-1)
                    iTmp2=strlen(saRet[2])-2;
                if(iTmp==0)
                    saRet[2]=saRet[2][iTmp2+2..<1];
                else if(iTmp2==strlen(saRet[2])-2)
                    saRet[2]=saRet[2][0..iTmp-1];
                else
                    saRet[2]=saRet[2][0..iTmp-1]+saRet[2][iTmp2+2..<1];
            }
            while((iTmp=strstr(saRet[2],"$T"))>=0) {
                iTmp2=strstr(saRet[2],"$T",iTmp+2);
                if(iTmp2==-1)
                    iTmp2=strlen(saRet[2])-2;
                if(iTmp==0)
                    saRet[2]=saRet[2][iTmp2+2..<1];
                else if(iTmp2==strlen(saRet[2])-2)
                    saRet[2]=saRet[2][0..iTmp-1];
                else
                    saRet[2]=saRet[2][0..iTmp-1]+saRet[2][iTmp2+2..<1];
            }
            saRet[2]=substitute(saRet[2],"$U","");
            saRet[2]=substitute(saRet[2],"$V",pluraliseVerb(sVerb));
            saTmp = explode(saRet[2], "$A");
            if(sizeof(saTmp) == 2) {
                if(sAdverb)  
                    saRet[2] = implode(saTmp, sAdverb);
                else 
                    saRet[2] = saTmp[0][0..<2]+saTmp[1];
            }
            saRet[2]=substitute(saRet[2],"$s","s");
        }

        return saRet;
    }
}

private void frogCurse(object oKisser,object oKissed) {
    if(oKissed->query_race()!="frog" && !oKissed->query_frog())
        return;
    else if(oKisser->query_race()=="frog" || oKisser->query_frog())
        return;
    else {
        oKisser->frog_curse(1);
        say(TP->TNAME+" turns into a frog!\n",0,oKisser,"");
        if(oKissed->query_player()) {
            oKissed->frog_curse(0);
            say(oKissed->TNAME+" stops being a frog!\n",0,oKissed,"");
        }
    }
}

int executeFeeling(string sVerb,string sStr) {
    string *saTmp,sTmp,sTarget,sAdverb;
    int iTmp,iRemote;
    object oTarget;

    if(sStr=="")
        sStr=(string)0;
    if(sStr) {
        if(sscanf(sStr,"%s %s",sTarget,sAdverb)!=2)
            sTarget=sStr;
    }

    if((sTmp=validRemoteFeeling(sVerb))) {
        iRemote=1;
        sVerb=sTmp;
    }
    else if((sTmp=validFeeling(sVerb)))
        sVerb=sTmp;
    else
//        return strlen(sVerb)>1 && sVerb[0..0]=="r";
        return 0;

#ifdef DEBUG
    printf("Parsed test string '%s%s' into the following components:\n\
%s%s%s\n",sVerb,sStr?" "+sStr:"",
(sVerb?"verb  : "+sVerb+"\n":""),
(sTarget?"target: "+sTarget+"\n":""),
(sAdverb?"adverb: "+sAdverb+"\n":""));
#endif // DEBUG

// This could actually be target OR adverb if not remote:
    if(sTarget) {
        if(iRemote)
            sTmp=matchName(sTarget,0);
        else
            sTmp=matchName(sTarget,2);
        if(sTmp) {
            if(iRemote)
                oTarget=find_player(sTmp);
            else
                oTarget=present(sTmp,environment(this_player()));

#ifdef DEBUG
            printf("Target '%s' matched. Proceeding.\n",sTmp);
#endif // DEBUG

        }
// If no target found, and note remote, assume that an adverb was intended.
        else if(!iRemote) {

#ifdef DEBUG
            printf("Assuming that \"%s\" is an adverb not a target.\n",
                   sTarget);
#endif // DEBUG

            sAdverb=sTarget;
            sTarget=(string)0;
        }
        else
            return 1;
    }

    if(sAdverb) {
        if((sTmp=validAdverb(sAdverb))) {
            sAdverb=sTmp;

#ifdef DEBUG
            printf("Adverb '%s' matched. Proceeding.\n",sAdverb);
#endif // DEBUG

        }
        else
            return 1;
    }

    saTmp=parseFeeling(sVerb[iRemote..<1],oTarget,sAdverb,iRemote);
    if(sizeof(saTmp)!=3)
        sTmp="\nDidn't receive the expected parsed msgs!\n";
    else {
        sTmp="\nFinal parsed feeling string for '"+sVerb+"':\n";
        if(saTmp[0]) {
            sTmp+="Msg_self  : ";
            if(iRemote)
                saTmp[0]="From afar, "+saTmp[0];
            saTmp[0]+="\n";
            sTmp+=saTmp[0];
        }
        if(saTmp[1]) {
            sTmp+="Msg_target: ";
            if(iRemote)
                saTmp[1]="From afar, "+saTmp[1];
            saTmp[1]+="\n";
            sTmp+=saTmp[1];
        }
        if(saTmp[2]) {
            sTmp+="Msg_other : ";
            if(iRemote)
                saTmp[2]="From afar, "+saTmp[2];
            saTmp[2]+="\n";
            sTmp+=saTmp[2];
        }
    }

#ifdef DEBUG
    write(sTmp+"\n");
#endif // DEBUG

    if(saTmp[0])
        write(saTmp[0]);
    if(saTmp[1] && oTarget)
        tell_object(oTarget,saTmp[1]);
    if(saTmp[2])
        say(saTmp[2],oTarget);
    if(sVerb=="kiss" && oTarget)
        frogCurse(this_player(),oTarget);
    return 1;
}

string executeChannelFeeling(string sStr,object *oaUsers) {
    string *saTmp,sTmp,sVerb,sTarget,sAdverb;
    int iTmp;
    object oTarget;

    if(sStr=="")
        sStr=(string)0;
    if(sStr) {
        iTmp=sscanf(sStr,"%s %s %s",sVerb,sTarget,sAdverb);
        if(iTmp!=3) {
            iTmp=sscanf(sStr,"%s %s",sVerb,sTarget);
            if(iTmp!=2)
                sVerb=sStr;
        }
    }

    if((sTmp=validFeeling(sVerb)))
        sVerb=sTmp;
    else {
        write("No feeling found to match '"+sVerb+"'.\n");
        return 0;
    }

#ifdef DEBUG
    printf("Parsed test string '%s' into the following components:\n\
%s%s%s\n",sStr,
(sVerb?"verb  : "+sVerb+"\n":""),
(sTarget?"target: "+sTarget+"\n":""),
(sAdverb?"adverb: "+sAdverb+"\n":""));
#endif // DEBUG

// This could actually be target OR adverb:
    if(sTarget) {
        sTmp=matchName(sTarget,3,oaUsers);
       if(sTmp) {
            oTarget=find_player(sTmp);

#ifdef DEBUG
            printf("Target '%s' matched. Proceeding.\n",sTmp);
#endif // DEBUG

        }
// If no target found, assume that an adverb was intended.
        else {

#ifdef DEBUG
            printf("Assuming that \"%s\" is an adverb not a target.\n",
                   sTarget);
#endif // DEBUG

            sAdverb=sTarget;
            sTarget=(string)0;
        }
    }

    if(sAdverb) {
        if((sTmp=validAdverb(sAdverb))) {
            sAdverb=sTmp;

#ifdef DEBUG
            printf("Adverb '%s' matched. Proceeding.\n",sAdverb);
#endif // DEBUG

        }
        else
            return 0;
    }

    saTmp=parseFeeling(sVerb,oTarget,sAdverb,2);
    if(sizeof(saTmp)!=3)
        sTmp="\nDidn't receive the expected parsed msgs!\n";
    else {
        sTmp="\nFinal parsed feeling string for '"+sVerb+"':\n";
        if(saTmp[0]) {
            sTmp+="Msg_self  : ";
            saTmp[0]+="\n";
            sTmp+=saTmp[0];
        }
        if(saTmp[1]) {
            sTmp+="Msg_target: ";
            saTmp[1]+="\n";
            sTmp+=saTmp[1];
        }
        if(saTmp[2]) {
            sTmp+="Msg_other : ";
            saTmp[2]+="\n";
            sTmp+=saTmp[2];
        }
    }

#ifdef DEBUG
    write(sTmp);
#endif // DEBUG

    return saTmp[2];
}
