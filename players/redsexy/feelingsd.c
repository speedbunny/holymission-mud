// Feelings daemon.                             Written by Sauron, 150997.
//								Modified by Redsexy, 100499.
// Key for symbols in feeling strings:
//      $Ns = Name of subject.
//      $Nv = Name of victim. ("yourself"/POSS+"self" if victim == subject)
//      $Os = Objective applied to the subject.
//      $Ov = Objective applied to the victim.
//      $Ps = Possessive applied to the subject.
//      $Pv = Possessive applied to the victim.
//      $Qs = Possessive name applied to the subject (<name>'s).
//      $Qv = Possessive name applied to the victim (<name>'s).
//      $Rs = Pronoun applied to the subject.
//      $Rv = Pronoun applied to the victim.
//	  $Lv = Self referrential (himself, herself, yourself).
//      $Is = Make the following text invisible to the subject,
//            but visible to the victim and 'others'.
//      $Vs = Make the following text visible to the subject only.
//      $Iv = Make the following text invisible to the victim,
//            but visible to the subject and 'others'.
//      $Vv = Make the following text visible to the victim only.
//      $Io = Make the following text invisible to the 'others',
//            but visible to the subject and victim.
//      $Vo = Make the following text visible to the 'others' only.
//      $Va = Reset all text visibility attributes.
//
//      $V  = Verb.
//      $A  = Adverb.
//      $s  = Add an 's' to the preceeding word (except for the msg sent
//            to the subject).

#include <adverbs.h>
#include <sys_defs.h>

#define FEELINGS        "/players/redsexy/feelings/"
#define SIMPLE          0
#define TARGET          1
#define ADVERB          2
#define DEF_ADVERB(o)   o->queryenv("DEF_ADVERB")

#undef DEBUG

int again(string sStr);
int dont(string sStr);
int fail(string sStr);
int suddenly(string sStr);

private mapping mFeelings, mAdverbs;

string pluraliseVerb(string sVerb) {
    return lower_case(pluralise(sVerb, 1));
}

void initFeelings() {
    string *saDir;
    int    i;

    if(!mFeelings) {
        saDir = get_dir(FEELINGS+".");
        mFeelings = ([]);
        for(i = 0; i < sizeof(saDir); i++) {
            if(saDir[i][<2..<1] == ".c") {
                saDir[i] = saDir[i][0..<3];
                mFeelings[saDir[i]] = FEELINGS+saDir[i];
            }
        }
    }
}

string *allFeelings() {
    initFeelings();
    return m_indices(mFeelings);
}

string displayFeelings() {
    return "The following feelings are globally available:\n\n"
           +list_array(allFeelings(), 0, 1)+"\n";
}

void initAdverbs() {
    if(!mAdverbs) {
        mAdverbs = ([]);
        mAdverbs['a'] = ADVERBS_A;
        mAdverbs['b'] = ADVERBS_B;
        mAdverbs['c'] = ADVERBS_C;
        mAdverbs['d'] = ADVERBS_D;
        mAdverbs['e'] = ADVERBS_E;
        mAdverbs['f'] = ADVERBS_F;
        mAdverbs['g'] = ADVERBS_G;
        mAdverbs['h'] = ADVERBS_H;
        mAdverbs['i'] = ADVERBS_I;
        mAdverbs['j'] = ADVERBS_J;
        mAdverbs['k'] = ADVERBS_K;
        mAdverbs['l'] = ADVERBS_L;
        mAdverbs['m'] = ADVERBS_M;
        mAdverbs['n'] = ADVERBS_N;
        mAdverbs['o'] = ADVERBS_O;
        mAdverbs['p'] = ADVERBS_P;
        mAdverbs['q'] = ADVERBS_Q;
        mAdverbs['r'] = ADVERBS_R;
        mAdverbs['s'] = ADVERBS_S;
        mAdverbs['t'] = ADVERBS_T;
        mAdverbs['u'] = ADVERBS_U;
        mAdverbs['v'] = ADVERBS_V;
        mAdverbs['w'] = ADVERBS_W;
        mAdverbs['x'] = ADVERBS_X;
        mAdverbs['y'] = ADVERBS_Y;
        mAdverbs['z'] = ADVERBS_Z;
    }
}

varargs string *allAdverbs(string sStr) {
    string *saTmp;
    int    i;

    initAdverbs();
    if(sStr && sStr != "")
        return mAdverbs[sStr[0]];
    else {
        saTmp = ({});
        for(i = 'a'; i <= 'z'; i++)
            saTmp += mAdverbs[i];
        return saTmp;
    }
}

string displayAdverbs() {
    return "The following adverbs are globally available:\n\n"
           +list_array(allAdverbs(), 0, 1)+"\n";
}

string validAdverb(string sMatch) {
    string *saAdverbs, *saTmp;
    int    i, iLen, iSz;

    initAdverbs();
    if(!sMatch || sMatch == "")
        return 0;
    else
        iLen = strlen(sMatch)-1;
    if(iLen < 1)        // Must enter 2 chars of the adverb to match.
        return (string)0;
    saAdverbs = mAdverbs[sMatch[0]];
    saTmp = ({});
    i = 0;
    iSz = sizeof(saAdverbs);
    for(i = 0; i < iSz; i++) {
        if(saAdverbs[i] == sMatch)
            return saAdverbs[i];
        if(saAdverbs[i][0..iLen] == sMatch)
            saTmp += ({saAdverbs[i]});
    }
    if(sizeof(saTmp) == 1)
        return saTmp[0];
    else if(sizeof(saTmp))
        notify_fail("The adverb \""+sMatch+"\" is ambiguous (\""
                    +list_array(saTmp, 1)+"\"). Please be more \
precise.\n");
    else
        notify_fail("No adverb found to match '"+sMatch+"'.\n");
}

varargs mixed validFeeling(string sMatch, int iFlag) {
    string *saFeelings, *saTmp;
    int    i, iLen, iSz;

    initFeelings();
    saFeelings = allFeelings();
    if(!sMatch || sMatch == "")
        return 0;
    else
        iLen = strlen(sMatch)-1;
    if(iLen < 2)        // Must enter 3 chars of the feeling to match.
        return 0;
    saTmp = ({});
    i = 0;
    iSz = sizeof(saFeelings);
    for(i = 0; i < iSz; i++) {
        if(saFeelings[i] == sMatch) {
            if(iFlag)
                return ({saFeelings[i]});
            else
                return saFeelings[i];
        }
        if(saFeelings[i][0..iLen] == sMatch)
            saTmp += ({saFeelings[i]});
    }
    if(iFlag)
        return saTmp;
    else if(sizeof(saTmp) == 1)
        return saTmp[0];
    else if(sizeof(saTmp))
        notify_fail("The feeling \""+sMatch+"\" is ambiguous (\""
                    +list_array(saTmp, 1)+"\"). \
Please be more precise.\n");

#ifdef DEBUG
    else
        notify_fail("No feeling found to match '"+sMatch+"'.\n");
#else
    else
        notify_fail("What?\n");
#endif // DEBUG

}

string validRemoteFeeling(string sMatch) {
    string *saTmp;

    if(sMatch && strlen(sMatch) > 1 && sMatch[0..0] == "r") {
        saTmp = validFeeling(sMatch[1..<1], 1);
        if(sizeof(saTmp) == 1)
            return "r"+saTmp[0];
        else if(sizeof(saTmp))
            notify_fail(sprintf("The remote feeling \"%s\" is ambiguous \
(\"%s\"). Please be more precise.\n", sMatch, list_array(saTmp, 1)));

#ifdef DEBUG
        else
            notify_fail("No remote feeling found to match '"
                        +sMatch+"'.\n");
#endif // DEBUG

    }
}

varargs string *parseFeeling(string sVerb, object oTarget, string sAdverb,
                             int iRemote, string sExtra) {
    string *saRet, *saTmp, sTmp, sRet;
    int    iTmp, iTmp2;
    object oSubject;

    oSubject = TP;
    saRet = allocate(3);

    if(sVerb) {
        saTmp = mFeelings[sVerb]->feelingInfo();
        if(oTarget) {
            sRet = saTmp[TARGET];
            if(!sRet) {
                sRet = saTmp[SIMPLE];
                oTarget = (object)0;
            }
        }
        else {
            sRet = saTmp[SIMPLE];
            if(!sRet || iRemote == 1) {
                printf("The feeling '%s%s' requires a target.\n",
                       (iRemote == 1 ? "r" : ""), sVerb);
                return saRet;
            }
        }

        if(sExtra) {
            if((sTmp = query_verb()) &&
               (sTmp == "dont" || sTmp == "don't" || sTmp == "fail"))
                sRet = replace_string(sRet, "$s", "");
            sRet = replace_string(sExtra, "$X", sRet[4..<2]);
        }

        if(!sAdverb && DEF_ADVERB(oSubject))
            sAdverb = DEF_ADVERB(oSubject);
        if(!sAdverb && saTmp[ADVERB])
            sAdverb = saTmp[ADVERB];

        saRet[0] = sRet;
        saTmp = explode(saRet[0], "$Ns");
        if(sizeof(saTmp) == 2) {
            if(iRemote == 1 || strlen(saTmp[0]))
                saRet[0] = implode(saTmp, "you");
            else
                saRet[0] = implode(saTmp, "You");
        }
        saRet[0] = replace_string(saRet[0], "$Os", "you");
        saRet[0] = replace_string(saRet[0], "$Ps", "your");
        saRet[0] = replace_string(saRet[0], "$Qs", "your");
        saRet[0] = replace_string(saRet[0], "$Rs", "you");
        saRet[0] = replace_string(saRet[0], "$Lv", "yourself");

        if(oTarget) {
            if(oTarget == oSubject) {
                saRet[0] = replace_string(saRet[0], "$Nv", "yourself");
                saRet[0] = replace_string(saRet[0], "$Ov", "you");
                saRet[0] = replace_string(saRet[0], "$Pv", "your own");
                saRet[0] = replace_string(saRet[0], "$Qv", "your own");
                saRet[0] = replace_string(saRet[0], "$Rv", "you");
                saRet[0] = replace_string(saRet[0], "$Lv", "yourself");

            }
            else {
                sTmp = oTarget->CRNAME;
                saRet[0] = replace_string(saRet[0], "$Nv", sTmp);
                saRet[0] = replace_string(saRet[0], "$Ov",
                                      oTarget->query_objective());
                saRet[0] = replace_string(saRet[0], "$Pv",
                                      oTarget->query_possessive());
                saRet[0] = replace_string(saRet[0], "$Qv",
                                      sTmp+(sTmp[<1..<1] == "s" ?
                                                "'" :
                                                "'s"));
                saRet[0] = replace_string(saRet[0], "$Rv",
                                      oTarget->query_pronoun());

                saRet[0] = replace_string(saRet[0], "$Lv",
                                      oTarget->query_objective()+"self");

            }
        }


        while((iTmp = strstr(saRet[0], "$Is")) >= 0) {
            iTmp2 = strstr(saRet[0], "$Va", iTmp+3);
            if(iTmp2 == -1)
                iTmp2 = strlen(saRet[0])-3;
            if(iTmp == 0)
                saRet[0] = saRet[0][iTmp2+3..<1];
            else if(iTmp2 == strlen(saRet[0])-3)
                saRet[0] = saRet[0][0..iTmp-1];
            else
                saRet[0] = saRet[0][0..iTmp-1]+saRet[0][iTmp2+3..<1];
        }
        saRet[0] = replace_string(saRet[0], "$Vs", "");
        saRet[0] = replace_string(saRet[0], "$Iv", "");
        while((iTmp = strstr(saRet[0], "$Vv")) >= 0) {
            iTmp2 = strstr(saRet[0], "$Va", iTmp+3);
            if(iTmp2 == -1)
                iTmp2 = strlen(saRet[0])-3;
            if(iTmp == 0)
                saRet[0] = saRet[0][iTmp2+3..<1];
            else if(iTmp2 == strlen(saRet[0])-3)
                saRet[0] = saRet[0][0..iTmp-1];
            else
                saRet[0] = saRet[0][0..iTmp-1]+saRet[0][iTmp2+3..<1];
        }
        saRet[0] = replace_string(saRet[0], "$Io", "");
        while((iTmp = strstr(saRet[0], "$Vo")) >= 0) {
            iTmp2 = strstr(saRet[0], "$Va", iTmp+3);
            if(iTmp2 == -1)
                iTmp2 = strlen(saRet[0])-3;
            if(iTmp == 0)
                saRet[0] = saRet[0][iTmp2+3..<1];
            else if(iTmp2 == strlen(saRet[0])-3)
                saRet[0] = saRet[0][0..iTmp-1];
            else
                saRet[0] = saRet[0][0..iTmp-1]+saRet[0][iTmp2+3..<1];
        }
        saRet[0] = replace_string(saRet[0], "$Va", "");

        saRet[0] = replace_string(saRet[0], "$V", sVerb);
        saRet[0] = replace_string(saRet[0], "$s", "");
        saTmp = explode(saRet[0], "$A");
        if(sizeof(saTmp) == 2) {
            if(sAdverb)
                saRet[0] = implode(saTmp, sAdverb);
            else
                saRet[0] = saTmp[0][0..<2]+saTmp[1];
        }

        if(oTarget && oTarget != oSubject) {
            saRet[1] = sRet;
            if(oSubject->is_invis_for(oTarget))
                saRet[1] = replace_string(saRet[1], "$Ns", CINAME);
            else
                saRet[1] = replace_string(saRet[1], "$Ns",
                                          oSubject->CRNAME);
            saRet[1] = replace_string(saRet[1], "$Os",
                                  oSubject->query_objective());
            saRet[1] = replace_string(saRet[1], "$Ps",
                                  oSubject->query_possessive());
            saRet[1] = replace_string(saRet[1], "$Qs",
                                  oSubject->query_possessive());
            saRet[1] = replace_string(saRet[1], "$Rs",
                                  oSubject->query_pronoun());

            saRet[1] = replace_string(saRet[1], "$Nv", "you");
            saRet[1] = replace_string(saRet[1], "$Ov", "you");
            saRet[1] = replace_string(saRet[1], "$Pv", "your");
            saRet[1] = replace_string(saRet[1], "$Qv", "your");
            saRet[1] = replace_string(saRet[1], "$Rv", "you");
            saRet[1] = replace_string(saRet[1], "$Lv", "yourself");

            saRet[1] = replace_string(saRet[1], "$Is", "");
            while((iTmp = strstr(saRet[1], "$Vs")) >= 0) {
                iTmp2 = strstr(saRet[1], "$Va", iTmp+3);
                if(iTmp2 == -1)
                    iTmp2 = strlen(saRet[1])-3;
                if(iTmp == 0)
                    saRet[1] = saRet[1][iTmp2+3..<1];
                else if(iTmp2 == strlen(saRet[1])-3)
                    saRet[1] = saRet[1][0..iTmp-1];
                else
                    saRet[1] = saRet[1][0..iTmp-1]+saRet[1][iTmp2+3..<1];
            }
            while((iTmp = strstr(saRet[1], "$Iv")) >= 0) {
                iTmp2 = strstr(saRet[1], "$Va", iTmp+3);
                if(iTmp2 == -1)
                    iTmp2 = strlen(saRet[1])-3;
                if(iTmp == 0)
                    saRet[1] = saRet[1][iTmp2+3..<1];
                else if(iTmp2 == strlen(saRet[1])-3)
                    saRet[1] = saRet[1][0..iTmp-1];
                else
         
           saRet[1] = saRet[1][0..iTmp-1]+saRet[1][iTmp2+3..<1];
            }
            saRet[1] = replace_string(saRet[1], "$Vv", "");
            saRet[1] = replace_string(saRet[1], "$Io", "");
            while((iTmp = strstr(saRet[1], "$Vo")) >= 0) {
                iTmp2 = strstr(saRet[1], "$Va", iTmp+3);
                if(iTmp2 == -1)
                    iTmp2 = strlen(saRet[1])-3;
                if(iTmp == 0)
                    saRet[1] = saRet[1][iTmp2+3..<1];
                else if(iTmp2 == strlen(saRet[1])-3)
                    saRet[1] = saRet[1][0..iTmp-1];
                else
                    saRet[1] = saRet[1][0..iTmp-1]+saRet[1][iTmp2+3..<1];
            }
            saRet[1] = replace_string(saRet[1], "$Va", "");

            if((sTmp = query_verb()) &&
               (sTmp == "dont" || sTmp == "don't" || sTmp == "fail"))
                saRet[1] = replace_string(saRet[1], "$V", sVerb);
            else
                saRet[1] = replace_string(saRet[1], "$V",
                                          pluraliseVerb(sVerb));
            saRet[1] = replace_string(saRet[1], "$s", "s");
            saTmp = explode(saRet[1], "$A");
            if(sizeof(saTmp) == 2) {
                if(sAdverb)
                    saRet[1] = implode(saTmp, sAdverb);
                    saRet[1] = saTmp[0][0..<2]+saTmp[1];
            }
        }

        if(iRemote != 1) {
            saRet[2] = sRet;
            if(iRemote)
                saRet[2] = replace_string(saRet[2], "$Ns",
                                       oSubject->CRNAME);
            saRet[2] = replace_string(saRet[2], "$Os",
                                  oSubject->query_objective());
            saRet[2] = replace_string(saRet[2], "$Ps",
                                  oSubject->query_possessive());
            saRet[2] = replace_string(saRet[2], "$Qs",
                                  oSubject->query_possessive());
            saRet[2] = replace_string(saRet[2], "$Rs",
                                  oSubject->query_pronoun());

            if(oTarget) {
                if(oTarget == oSubject) {
                    saRet[2] = replace_string(saRet[2], "$Nv",
                                          oSubject->query_objective()+"self");
                    saRet[2] = replace_string(saRet[2], "$Ov",
                                          oSubject->query_objective());
                    saRet[2] = replace_string(saRet[2], "$Pv",
                                          oSubject->query_possessive()+" own");
                    saRet[2] = replace_string(saRet[2], "$Qv",
                                          oSubject->query_possessive()+" own");
                    saRet[2] = replace_string(saRet[2], "$Rv",
                                          oSubject->query_pronoun());
                }
                else {
                    if(iRemote)
                        sTmp = oTarget->CRNAME;
                    else
                        sTmp = oTarget->NAME;
                    saRet[2] = replace_string(saRet[2], "$Nv", sTmp);
                    saRet[2] = replace_string(saRet[2], "$Ov", sTmp);
                    saRet[2] = replace_string(saRet[2], "$Pv",
                                          oTarget->query_possessive());
                    saRet[2] = replace_string(saRet[2], "$Qv",
                                          sTmp+(sTmp[<1..<1] == "s" ?
                                                    "'" :
                                                    "'s"));
                    saRet[2] = replace_string(saRet[2], "$Rv",
                                          oTarget->query_pronoun());
                }
            }


            saRet[2] = replace_string(saRet[2], "$Is", "");
            while((iTmp = strstr(saRet[2], "$Vs")) >= 0) {
                iTmp2 = strstr(saRet[2], "$Va", iTmp+3);
                if(iTmp2 == -1)
                    iTmp2 = strlen(saRet[2])-3;
                if(iTmp == 0)
                    saRet[2] = saRet[2][iTmp2+3..<1];
                else if(iTmp2 == strlen(saRet[2])-3)
                    saRet[2] = saRet[2][0..iTmp-1];
                else
                    saRet[2] = saRet[2][0..iTmp-1]+saRet[2][iTmp2+3..<1];
            }
            saRet[2] = replace_string(saRet[2], "$Iv", "");
            while((iTmp = strstr(saRet[2], "$Vv")) >= 0) {
                iTmp2 = strstr(saRet[2], "$Va", iTmp+3);
                if(iTmp2 == -1)
                    iTmp2 = strlen(saRet[2])-3;
                if(iTmp == 0)
                    saRet[2] = saRet[2][iTmp2+3..<1];
                else if(iTmp2 == strlen(saRet[2])-3)
                    saRet[2] = saRet[2][0..iTmp-1];
                else
                    saRet[2] = saRet[2][0..iTmp-1]+saRet[2][iTmp2+3..<1];
            }
            while((iTmp = strstr(saRet[2], "$Io")) >= 0) {
                iTmp2 = strstr(saRet[2], "$Va", iTmp+3);
                if(iTmp2 == -1)
                    iTmp2 = strlen(saRet[2])-3;
                if(iTmp == 0)
                    saRet[2] = saRet[2][iTmp2+3..<1];
                else if(iTmp2 == strlen(saRet[2])-3)
                    saRet[2] = saRet[2][0..iTmp-1];
                else
                    saRet[2] = saRet[2][0..iTmp-1]+saRet[2][iTmp2+3..<1];
            }
            saRet[2] = replace_string(saRet[2], "$Vo", "");
            saRet[2] = replace_string(saRet[2], "$Va", "");

            if((sTmp = query_verb()) &&
               (sTmp == "dont" || sTmp == "don't" || sTmp == "fail"))
                saRet[2] = replace_string(saRet[2], "$V", sVerb);
            else
                saRet[2] = replace_string(saRet[2], "$V",
                                          pluraliseVerb(sVerb));
            saRet[2] = replace_string(saRet[2], "$s", "s");
            saTmp = explode(saRet[2], "$A");
            if(sizeof(saTmp) == 2) {
                if(sAdverb)
                    saRet[2] = implode(saTmp, sAdverb);
                else
                    saRet[2] = saTmp[0][0..<2]+saTmp[1];
            }
        }

        return saRet;
    }
}

private void frogCurse(object oKisser, object oKissed) {
    if(oKissed->query_race() != "frog" && !oKissed->query_frog())
        return;
    else if(oKisser->query_race() == "frog" || oKisser->query_frog())
        return;
    else {
        oKisser->frog_curse(1);
        say(TP->CRNAME+" turns into a frog!\n", 0, oKisser, "");
        if(oKissed->query_player()) {
            oKissed->frog_curse(0);
            say(oKissed->CRNAME+" stops being a frog!\n", 0, oKissed, "");
        }
}

varargs int executeFeeling(string sVerb, string sStr, string sExtra) {
    string *saTmp, sTmp, sTarget, sAdverb;
    int    iTmp, iRemote;
    object oTarget;

    if(sStr == "")
        sStr = (string)0;

    if(sVerb == "again")
        return again(sStr);
    else if(sVerb == "dont" || sVerb == "don't")
        return dont(sStr);
    else if(sVerb == "fail")
        return 
fail(sStr);
    else if(sVerb == "suddenly")
        return suddenly(sStr);
    else if(sStr) {
            if(sscanf(sStr, "%s %s", sTarget, sAdverb) != 2)
            sTarget = sStr;
    }

    if(query_verb() && query_verb() == sVerb &&
       (sTmp = validRemoteFeeling(sVerb))) {
        iRemote = 1;
        sVerb = sTmp;
    }
    else if((sTmp = validFeeling(sVerb)))
        sVerb = sTmp;
    else
        return 0;

#ifdef DEBUG
    printf("Parsed test string '%s%s' in
to the following components:\n\
%s%s%s\n", sVerb, sStr ? " "+sStr : "",
(sVerb ? "verb  : "+sVerb+"\n" : ""),
(sTarget ? "target: "+sTarget+"\n" : ""),
(sAdverb ? "adverb: "+sAdverb+"\n" : ""));
#endif // DEBUG

// This could actually be target OR adverb if not remote:
    if(sTarget) {
        if(iRemote)
            sTmp = match_name(sTarget, 0);
        else
            sTmp = match_name(sTarget, 2);
        if(sTmp) {
            if(iRemote)
                oTarget = find_player(sTmp);
            else
                oTarget = present(sTmp, ENV(TP));

#ifdef DEBUG
            printf("Target '%s' matched. Proceeding.\n", sTmp);
#endif // DEBUG

        }
// If no target found, and not remote, assume that an adverb was intended.
else if(!sAdverb && !iRemote) {

#ifdef DEBUG
            printf("Assuming that \"%s\" is an adverb not a target.\n",
                   sTarget);
#endif // DEBUG

            sAdverb = sTarget;
          
  sTarget = (string)0;
        }
        else
            return 0;
    }

    if(sAdverb) {
        if((sTmp = validAdverb(sAdverb))) {
            sAdverb = sTmp;

#ifdef DEBUG
            printf("Adverb '%s' matched. Proceeding.\n",sAdverb);
#endif // DEBUG

        }
        else
            return 0;
    }

    saTmp = parseFeeling(sVerb[iRemote..<1], oTarget, sAdverb, iRemote,
                         sExtra);
    if(sizeof(saTmp) != 3)

        sTmp = "\nDidn't receive the expected parsed msgs!\n";
    else {
        sTmp = "\nFinal parsed feeling string for '"+sVerb+"':\n";
        if(saTmp[0]) {
            sTmp += "Msg_self  : ";
            if(iRemote)
                saTmp[0] = "From afar, "+saTmp[0];
            saTmp[0] += "\n";
            sTmp += saTmp[0];
        }
        if(saTmp[1]) {
            sTmp += "Msg_target: ";
            if(iRemote)
                saTmp[1] = "From afar, "+saTmp[1];
            saTmp[1] += "\n";
            sTmp += saTmp[1];
        }
        if(saTmp[2]) {
            sTmp += "Msg_other : ";
            if(iRemote)
                saTmp[2] = "From afar, "+saTmp[2];
            saTmp[2] += "\n";
            sTmp += saTmp[2];
        }
    }

#ifdef DEBUG
    wrap_text(sTmp, 2);
#endif // DEBUG

    if(saTmp[0])
        wrap_text(saTmp[0], 2);
    if(saTmp[1] && oTarget)
        tell_object(oTarget, wrap_text(saTmp[1]));
    if(saTmp[2])
        say(wrap_text(replace_string(saTmp[2], "$Ns", TP->CRNAME)),
            oTarget, TP,
            wrap_text(replace_string(saTmp[2], "$Ns", CINAME)));
    if(sVerb == "kiss" && oTarget)
        frogCurse(TP, oTarget);
    else if(sVerb == "tickle" && oTarget) {
        if(random(2))
            command("laugh", oTarget);
        else
            command("giggle", oTarget);
    }
    else if(sVerb == "beep" && oTarget)
        tell_object(oTarget, "\a");
    return 1;
}

string executeChannelFeeling(string sStr, object *oaUsers) {
    string *saTmp, sTmp, sVerb, sTarget, sAdverb;
    int    iTmp;
    object oTarget;

    if(sStr == "")
        sStr = (string)0;
    if(sStr) {
        iTmp = sscanf(sStr, "%s %s %s", sVerb, sTarget, sAdverb);
        if(iTmp != 3) {
            iTmp = sscanf(sStr, "%s %s", sVerb, sTarget);
            if(iTmp != 2)
                sVerb = sStr;
        }
    }

    if((sTmp = validFeeling(sVerb)))
        sVerb = sTmp;
    else {
        notify_fail("No feeling found to match '" + sVerb + "'.\n");
        return 0;
    }

#ifdef DEBUG
    printf("Parsed test string '%s' into the following components:\n\
%s%s%s\n", sStr,
(sVerb ? "verb  : "+sVerb+"\n" : ""),
(sTarget ? "target: "+sTarget+"\n" : ""),
(sAdverb ? "adverb: "+sAdverb+"\n" : ""));
#endif // DEBUG

// This could actually be target OR adverb:
    if(sTarget) {
        sTmp = match_name(sTarget, 4, oaUsers);
       if(sTmp) {
            oTarget = find_player(sTmp);

#ifdef DEBUG
            printf("Target '%s' matched. Proceeding.\n", sTmp);
#endif // DEBUG

        }
// If no target found, assume that an adverb was intended.
        else {

#ifdef DEBUG
            printf("Assuming that \"%s\" is an adverb not a target.\n",
                   sTarget);
#endif // DEBUG

            sAdverb = sTarget;
            sTarget = (string)0;
        }
    }

    if(sAdverb) {
        if((sTmp = validAdverb(sAdverb))) {
            sAdverb = sTmp;

#ifdef DEBUG
            printf("Adverb '%s' matched. Proceeding.\n",sAdverb);
#endif // DEBUG

        }
        else
            return 0;
    }

    saTmp = parseFeeling(sVerb, oTarget, sAdverb, 2);
    if(sizeof(saTmp) != 3)
        sTmp = "\nDidn't receive the expected parsed msgs!\n";
    else {
        sTmp = "\nFinal parsed feeling string for '"+sVerb+"':\n";
        if(saTmp[0]) {
            sTmp += "Msg_self  : ";
            saTmp[0] += "\n";
            sTmp += saTmp[0];
        }
        if(saTmp[1]) {
            sTmp += "Msg_target: ";
            saTmp[1] += "\n";
            sTmp += saTmp[1];
        }
        if(saTmp[2]) {
            sTmp += "Msg_other : ";
            saTmp[2] += "\n";
            sTmp += saTmp[2];
        }
    }

#ifdef DEBUG
    wrap_text(sTmp, 2);
#endif // DEBUG

    return saTmp[2];
}

int again(string sStr) {
    string sExtra, *saArr;
    notify_fail("Do what what?\n");
    sExtra = "$Ns $X, again.";

    if(sStr && sStr != "")
        saArr = explode(sStr, " ");

    if(saArr && sizeof(saArr) == 1)
        return executeFeeling(sStr, 0, sExtra);
    else if(saArr && sizeof(saArr))
        return executeFeeling(saArr[0], implode(saArr[1..<1], " "),
                              sExtra);
    else
        return 0;
}

int dont(string sStr) {
    string sExtra, *saArr;

    notify_fail("Don't what?\n");
    sExtra = "$Ns tr$Vsy$Va$Isies$Va not to $X, but fail$s miserably.";

    if(sStr && sStr != "")
        saArr = explode(sStr, " ");

    if(saArr && sizeof(saArr) == 1)
        return executeFeeling(sStr, 0, sExtra);
    else if(saArr && sizeof(saArr))
        return executeFeeling(saArr[0], implode(saArr[1..<1], " "),
                              sExtra);
    else
        return 0;
}

int fail(string sStr) {
    string sExtra, *saArr;

    notify_fail("Fail to do  what?\n");
    sExtra = "$Ns tr$Vsy$Va$Isies$Va to $X, but fail$s miserably.";

    if(sStr && sStr != "")
        saArr = explode(sStr, " ");

    if(saArr && sizeof(saArr) == 1)
        return executeFeeling(sStr, 0, sExtra);
    else if(saArr && sizeof(saArr))
        return executeFeeling(saArr[0], implode(saArr[1..<1], " "),
                              sExtra);
    else
        return 0;
}

int suddenly(string sStr) {
    string sExtra, *saArr;

    notify_fail("Suddenly what?\n");
    sExtra = "Suddenly, $Ns $X.";

    if(sStr && sStr != "")
        saArr = explode(sStr, " ");

    if(saArr && sizeof(saArr) == 1)
        return executeFeeling(sStr, 0, sExtra);
    else if(saArr && sizeof(saArr))
        return executeFeeling(saArr[0], implode(saArr[1..<1], " "),
                              sExtra);
    else
        return 0;
}
