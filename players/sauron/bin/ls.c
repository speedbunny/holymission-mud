inherit "/players/sauron/clone/ldup_cmds/extras";

#pragma strict_types
#pragma save_types

int main(string sStr) {
    string sFile, sTmp, d, sRet, sOwn, sGrp, sPerm, *saArr;
    int    i, j, iSize, iDirs, iFiles, iDate, iFileDate;
    mixed  *xaArr;

    if(sStr && sscanf(sStr, "-l %s", sTmp) == 1) {
        iDate = 1;
        sStr = sTmp;
    }
    else if(sStr == "-l") {
        iDate = 1;
        sStr = (string)0;
    }

    sStr = lib_fn_expand(sStr);
    if(!sStr || sStr == "")
        return 1;

    else if(!(string)this_player()->valid_read(sStr)){
        printf("%s: Access denied!\n", sStr);
        return 1;
    }

    iSize = file_size(sStr);
    switch(iSize) {
        case -2:
            if(sStr[<1..<1] != "/")
                sStr += "/";
            saArr = get_dir(sStr+".");
            xaArr = get_dir(sStr+".", -1);
            sRet = sprintf("File list for '%s':\n\n", sStr);
            break;
        case -1:
            if(member(sStr, '?') == -1 && member(sStr, '*') == -1) {
                printf("%s: No such file or directory.\n", sStr);
                return 1;
            }
            else {
                saArr = get_dir(sStr);
                xaArr = get_dir(sStr, -1);
            }
            if(!sizeof(xaArr)) {
                printf("%s: No match.\n", sStr);
                return 1;
            }
            else {
                sRet = sprintf("File list for '%s':\n\n", sStr);
                sStr = implode(explode(sStr, "/")[0..<2], "/")+"/";
            }
            break;
        default:
            saArr = get_dir(sStr);
            xaArr = get_dir(sStr, -1);
            sRet = sprintf("File list for '%s':\n\n", sStr);
            break;
    }

    iSize = 0;
    iDirs = iFiles = 0;
    if(iDate) {
        for(i = 0; i < sizeof(saArr); i++) {
            j = member_array(saArr[i], xaArr);
            iSize = xaArr[j+1];
            iFileDate = xaArr[j+2];
            if(time()-iFileDate > 15724800) // half a year
                d = ctime(iFileDate)[4..10]+ctime(iFileDate)[<5..<1];
            else
                d = ctime(iFileDate)[4..15];
            if(sscanf(sStr+saArr[i], "/players/%s/%s", sOwn, sTmp) == 2) {
                sGrp = "users";
                sPerm = "-rw----";
                if(sOwn == (string)this_player()->query_real_name())
                    sPerm[4..4] = "r";
                else {
                    if(this_player()->valid_read(sStr+saArr[i])) {
                        sPerm[4..4] = "r";
                        if(this_player()->valid_write(sStr+saArr[i]) &&
                            sOwn != "sauron")
                            sPerm[5..5] = "w";
                    }
                }
                sPerm += sPerm[<3..<1];
            }
            else if(sscanf(sStr+saArr[i], "/players/%s", sOwn)==1) {
                sGrp = "backbone";
                sPerm = "-rw----";
                if(sOwn == (string)this_player()->query_real_name())
                    sPerm[4..4] = "r";
                else {
                    if(this_player()->valid_read(sStr+saArr[i])) {
                        sPerm[4..4] = "r";
                        if(this_player()->valid_write(sStr+saArr[i]) &&
                            sOwn != "sauron")
                            sPerm[5..5] = "w";
                    }
                }
                sPerm += sPerm[<3..<1];
            }
            else {
                sOwn = sGrp = "backbone";
                sPerm = "-rw----";
                if(this_player()->valid_read(sStr+saArr[i])) {
                    sPerm[4..4] = "r";
                    if(this_player()->valid_write(sStr+saArr[i]))
                        sPerm[5..5] = "w";
                }
                sPerm += sPerm[<3..<1];
            }
            if(iSize != -2) {
                if(!iSize)
                    iSize = 1;
                sFile = saArr[i];
                if(find_object(sStr+saArr[i]))
                    sPerm[0..0] = "*";
                sRet = sprintf("%s%10s   1 %-11s %-8s %8d %s %s\n",
                               sRet, sPerm, sOwn, sGrp, iSize, d, sFile);
                iFiles++;
            }
            else {
                sFile = saArr[i]+"/";
                sPerm[0..0] = "d";
                sPerm[3..3] = "x";
                if(sPerm[4..4] == "r")
                    sPerm[6..6] = "x";
                if(sPerm[7..7] == "r")
                    sPerm[9..9] = "x";
                sRet = sprintf("%s%10s   1 %-11s %-8s %8d %s %s\n",
                               sRet, sPerm, sOwn, sGrp, 1024, d, sFile);
                iDirs++;
            }
        }
    }
    else {
        for(i = 0; i < sizeof(saArr); i += 3) {
            j = member_array(saArr[i], xaArr);
            iSize = xaArr[j+1];
            if(iSize == -2) {
                sFile = saArr[i]+"/";
                sRet = sprintf("%s%4s   %-19s",
                               sRet,
                               this_player()->valid_read(sStr+saArr[i]) ?
                                   "+" :
                                   "-",
                               sFile);
                iDirs++;
            }
            else {
                if(!iSize)
                    iSize = 1;
                sFile = saArr[i];
                sRet = sprintf("%s%4d %s %-19s", sRet, iSize/1024+1,
                               (find_object(sStr+saArr[i]) ? "*" : " "),
                               sFile);
                iFiles++;
            }
            if((i+1) < sizeof(saArr)) {
                j = member_array(saArr[i+1], xaArr);
                iSize = xaArr[j+1];
                if(iSize == -2) {
                    sFile = saArr[i+1]+"/";
                    sRet = sprintf("%s%4s   %-19s",
                                   sRet,
                                   this_player()->valid_read(sStr+saArr[i+1]) ?
                                       "+" :
                                       "-",
                                   sFile);
                    iDirs++;
                }
                else {
                    if(!iSize)
                        iSize = 1;
                    sFile = saArr[i+1];
                    sRet = sprintf("%s%4d %s %-19s", sRet, iSize/1024+1,
                                   (find_object(sStr+saArr[i+1]) ? "*" : " "),
                                   sFile);
                    iFiles++;
                }
            }
            if((i+2) < sizeof(saArr)) {
                j = member_array(saArr[i+2], xaArr);
                iSize = xaArr[j+1];
                if(iSize == -2) {
                    sFile = saArr[i+2]+"/";
                    sRet = sprintf("%s%4s   %-19s",
                                   sRet,
                                   this_player()->valid_read(sStr+saArr[i+2]) ?
                                       "+" :
                                       "-",
                                   sFile);
                    iDirs++;
                }
                else {
                    if(!iSize)
                        iSize = 1;
                    sFile = saArr[i+2];
                    sRet = sprintf("%s%4d %s %-19s", sRet, iSize/1024+1,
                                   (find_object(sStr+saArr[i+2]) ? "*" : " "),
                                   sFile);
                    iFiles++;
                }
            }
            sRet += "\n";
        }
    }
    sRet = sprintf("%s\nDirectories: %d  Files: %d  Total: %d\n",
                  sRet, iDirs, iFiles, iDirs+iFiles);
    this_player()->more_string(sRet);
    return 1;
}
