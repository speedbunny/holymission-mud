#include <sys_defs.h>

int main(string sStr) {
    string q, w, e, r, sName, sFile, sBytes, *saFile, sTmp;
    int    i, iNum, iStart, iBlock;
    object *oaInv, *oaEnv;

    if(!sStr || sStr == "" || sStr == "here") 
        sName = "/"+file_name(ENV(TP), 1);
    else {
        sscanf(sStr, "%s.c", sStr);
        oaInv = ALL(TP);
        oaEnv = ALL(ENV(TP));
        for(i = 0; i < sizeof(oaInv); i++) {
            sTmp = "/"+file_name(oaInv[i], 1);
            if(!sName &&
               (oaInv[i]->id(sStr) || explode(sTmp, "/")[<1] == sStr))
                sName = sTmp;
            else
                continue;
        }
        for(i = 0; i < sizeof(oaEnv); i++) {
            sTmp = "/"+file_name(oaEnv[i], 1);
            if(!sName &&
               (oaEnv[i]->id(sStr) || explode(sTmp, "/")[<1] == sStr))
                sName = sTmp;
            else
                continue;
        }
        if(!sName)
            sName = clean_path(sStr, 1);
    }

    if(!sName || sName == "")
        return 1;
    else if(!(string)TP->valid_read(sName)) {
        printf("%s: Access denied!\n", sName);
        return 1;
    }
    else
        sName += ".c";

    if(!file_exists(sName, 1))
        return 1;

    iStart = 0; 
    iBlock=50000;
    sFile = "";

    while(iStart < file_size(sName)) {
        sBytes = read_bytes(sName, iStart, iBlock);
        if(!sBytes) {
            printf("actions: Error reading file %s at byte %d.\n",
                   sName, iStart);
            return 1;
        }
        sFile += sBytes;
        iStart += iBlock;
    }

    iNum = 0;
    saFile = explode(sFile, "\n");
    printf("Looking for add_actions in %s:", sName);

    for(i = 0; i < sizeof(saFile); i++) {
        if(sscanf(saFile[i], "%sadd_action%s(%s)%s", q, w, e, r) > 0) {
            if(!iNum)
                write("\n");
            printf("\nAdd_action found on line %d:\n%s", i+1, saFile[i]);
            iNum++;
        }
        else if(sscanf(saFile[i], "%sAA%s(%s)%s", q, w, e, r) > 0) {
            if(!iNum)
                write("\n");
            printf("\nAdd_action found on line %d:\n%s", i+1, saFile[i]);
            iNum++;
        }
        else
            continue;
    }
    printf("\n\n%d add_action%s found.\n",
           iNum, iNum == 1 ? "" : "s");
    return 1;
}
