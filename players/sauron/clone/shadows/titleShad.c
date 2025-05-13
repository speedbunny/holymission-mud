inherit "/obj/std_shadow";

varargs int set_pretitle(string sStr,int iSilent) {
    int iRet;
    object oTp;

    oTp=this_interactive();
    if(me && oTp==me)
        return me->set_pretitle(sStr,iSilent);
    else {
        iRet=oTp->set_pretitle(sStr,iSilent);
        oTp->save_me(0);
        tell_object(me, oTp->query_real_name(1)+" tried to set your pretitle to '"
                        +sStr+"'.\n");
        return iRet;
    }
}

int set_title(string sStr) {
    int iRet;
    object oTp;

    oTp=this_interactive();
    if(me && oTp==me)
        return me->set_title(sStr);
    else {
        iRet=oTp->set_title(sStr);
        oTp->save_me(0);
        tell_object(me, oTp->query_real_name(1)+" tried to set your title to '"
                        +sStr+"'.\n");
        return iRet;
    }
}

int set_race(string sStr) {
    int iRet;
    object oTp;

    oTp=this_interactive();
    if(me && oTp==me)
        return me->set_race(sStr);
    else {
        iRet=oTp->set_race(sStr);
        oTp->save_me(0);
        tell_object(me, oTp->query_real_name(1)+" tried to set your race to '"
                        +sStr+"'.\n");
        return iRet;
    }
}

int immunity_paralyze() {
    return 1;
}

int titleShad() {
    return 1;
}

object titleObject() {
    return this_object();
}
