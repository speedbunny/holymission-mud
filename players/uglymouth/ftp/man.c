#include <sys_bin.h>
#include <sys_defs.h>

#define MANUALS		"/doc/"

mapping mManuals,	// <topic> : ({ <sub_topics> })
        mPaths;		// <topic> : <path>

int dirFilter(string sDir, string sPath) {
    return sDir != "." && sDir != ".." && file_size(sPath+sDir) == -2;
}

static compileManualDirs(string sDir) {
    string sTmp, *saTmp;
    int    i, iSz;

    saTmp = get_dir(sDir+".");
    mManuals[explode(sDir, "/")[<2]] = saTmp;
    saTmp = filter_array(saTmp, "dirFilter", TO, sDir);
    iSz = sizeof(saTmp);
    for(i = 0; i < iSz; i++) {
        if(mPaths[saTmp[i]]) {
            log_file("MAN", "Duplicate man dir: "+sDir+saTmp[i]
                           +"\n                   "+mPaths[saTmp[i]]
                           +"\n");
            continue;
        }
        else {
            mPaths[saTmp[i]] = sDir+saTmp[i]+"/";
            compileManualDirs(mPaths[saTmp[i]]);
        }
    }
}

void test() {
    printf("mManuals == %s\nmPaths == %s\n",
           print_var(mManuals), print_var(mPaths));
}

int filter(string sStr, string sTopic) {
    return strstr(mPaths[sStr], sTopic) != -1;
}

int main(string sStr) {
    string  sRet, sTmp, *saMan, *saTmp;
    int     i, iSz;
    mapping mTmp;

    if(!mManuals) {
        mManuals = ([]);
        mPaths = (["doc": MANUALS]);
        compileManualDirs(MANUALS);
    }

    if(!sStr || sStr == "" || sStr == "doc") {
// Only subdirs in the /doc/ dir so no need to split the listing...
        printf("man: There are manual entries on the following \
topics:\n\n%s\n", lw(list_array(mManuals["doc"])));
        return 1;
    }
    else
        saTmp = explode(sStr, " ");

    if(sizeof(saTmp) == 2) {
        sTmp = saTmp[0];
        sStr = saTmp[1];
        if(sTmp == "doc" || !mPaths[sTmp]) {
            printf("man: %s: Invalid topic.\n", sTmp);
            return 1;
        }
        else
            mTmp = filter_mapping(mPaths, "filter", TO, sTmp);

        if(mTmp[sStr]) {
            saMan = saTmp = ({});
            iSz = sizeof(mManuals[sStr]);
            for(i = 0; i < iSz; i++) {
                if(mPaths[mManuals[sStr][i]] &&
                   strstr(mPaths[mManuals[sStr][i]], mPaths[sStr]) != -1)
                    saTmp += ({mManuals[sStr][i]});
                else
                    saMan += ({mManuals[sStr][i]});
            }
            if(sizeof(saTmp))		// Sub-topics:
                sRet = "man: The topic '"+mPaths[sStr]+"' contains the \
following sub-topics:\n\n"+lw(list_array(saTmp))+"\n";
            if(sizeof(saMan)) {		// Manual entries:
                if(sRet)
                    sRet += ("\nand the following manual entries:\n\n"
+lw(list_array(saMan))+"\n");
                else
                    sRet = "man: The topic '"+mPaths[sStr]+"' contains \
the following manual entries:\n\n"+lw(list_array(saMan))+"\n";
            }
            if(sRet)
                return (int)TP->more_string(sRet);
            else {
                printf("man: The topic '%s' is empty.\n", mPaths[sStr]);
                return 1;
            }
        }
        else {
            saTmp = m_values(mTmp);
            iSz = sizeof(saTmp);
            for(i = 0; i < iSz; i++) {
                if(file_size(saTmp[i]+sStr) > 0)
                    return (int)TP->more_string("man: The topic '"
+saTmp[i]+sStr+"' has the following manual entry:\n\n"
+read_file(saTmp[i]+sStr));
            }
        }
        printf("man: Topic '%s' not found in %s.\n",
               sStr, mPaths[sTmp]);
        return 1;
    }
    else if(sizeof(saTmp) != 1) {
        printf("man: %s: Invalid argument.\n", sStr);
        return 1;
    }
    else {
        if(mManuals[sStr]) {
            saMan = saTmp = ({});
            iSz = sizeof(mManuals[sStr]);
            for(i = 0; i < iSz; i++) {
                if(mPaths[mManuals[sStr][i]] && 
                   strstr(mPaths[mManuals[sStr][i]], mPaths[sStr]) != -1)
                    saTmp += ({mManuals[sStr][i]});
                else
                    saMan += ({mManuals[sStr][i]});
            }
            if(sizeof(saTmp))		// Sub-topics:
                sRet = "man: The topic '"+mPaths[sStr]+"' contains the \
following sub-topics:\n\n"+lw(list_array(saTmp))+"\n";
            if(sizeof(saMan)) {		// Manual entries:
                if(sRet)
                    sRet += ("\nand the following manual entries:\n\n"
+lw(list_array(saMan))+"\n");
                else
                    sRet = "man: The topic '"+mPaths[sStr]+"' contains \
the following manual entries:\n\n"+lw(list_array(saMan))+"\n";
            }
            if(!sRet)
                sRet = "man: The topic '"+mPaths[sStr]+"' is empty.\n";
        }

        saMan = m_values(mPaths);
        iSz = sizeof(saMan);
        for(i = 0; i < iSz; i++) {
            if(file_size(saMan[i]+sStr) > 0) {
                if(!sRet)
                    sRet = "";
                else
                    sRet += "\n";
                sRet += ("man: The topic '"+saMan[i]+sStr+"' has the \
following manual entry:\n\n"+read_file(saMan[i]+sStr));
            }
        }

        if(sRet)
            return (int)TP->more_string(sRet);
        else {
            if(mPaths[sStr])
                printf("man: The topic '%s' is empty.\n", mPaths[sStr]);
            else
                printf("man: %s: Not found.\n", sStr);
            return 1;
        }
    }
}

//----------------------- Functions used by 'help'. -----------------------

varargs string queryArguments(int iFlag) {
    if(iFlag)
        return " <topic>";
    else
        return "none, or a topic";
}

string queryExamples() {
    return "man, man efun, man efun sizeof";
}

int queryCatagory() {
    return INFO;
}

string help() {
    return "\
This command displays on-line manual pages, providing help on various \
coding matters. You can search for a man page within a specific topic by \
specifying that topic before the topic you are searching for. For \
example, there is more than 1 match to the topic 'armour', but using the \
command 'man build armour' will just display that man page. If you are \
looking for general help on wizard matters, and you can't find it here, \
try 'help general' to see if the list of wizard topics there tell you \
what you want to know. In particular, all wizard command help is now \
handled by the help command.\n";
}
