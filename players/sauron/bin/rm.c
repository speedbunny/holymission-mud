#include <sys_defs.h>

int main(string sStr) {
    string *saFiles, *saArr, sPath;
    int    i;

    if(!sStr || sStr == "") {
        write("Syntax: rm <file(s)>\n");
        return 1;
    }
    else
        sStr = clean_path(sStr, 1);

    if(!sStr || sStr == "")
        return 1;
    else if(!(string)TP->valid_read(sStr)) {
        printf("%s: Access denied!\n", sStr);
        return 1;
    }
    else {
        sPath = implode(explode(sStr, "/")[0..<2], "/")+"/";
        saFiles = get_dir(sStr);
    }

    if(!sizeof(saFiles) && file_size(sStr) == -2) {
        sPath = sStr+"/";
        saFiles = get_dir(sStr+"/.");
    }
    if(!sizeof(saFiles)) {
        printf("%s: No such file or directory.\n", sStr);
        return 1;
    }

    for(i = 0; i < sizeof(saFiles); i++) {
        if(saFiles[i] == "." || saFiles[i] == "..")
            continue;
        else if(rm(sPath+saFiles[i]))
            printf("rm: Removed: %s%s\n", sPath, saFiles[i]);
        else if(rmdir(sPath+saFiles[i]))
            printf("rm: Removed directory: %s%s\n", sPath, saFiles[i]);
        else {
            printf("rm: Cannot remove: %s%s", sPath, saFiles[i]);
            if(file_size(sPath+saFiles[i]) == -2)
                write(" (maybe it's not empty)");
            write("\n");
        }
    }
    return 1;
}
