#include "/include/defs.h"

int main(string str) {

    string path;

    if(!str) return 0;

    if(str == "levels") {
        GM->list_levels(9,TP->query_gender());        
        return 1;
    }
    if(str == "legendlevels") {
        GM->list_legend_levels(9,TP->query_gender());
        return 1;
    }
    path = "/players/redsexy/guild/help/" + str;
    if(file_size(path) >= 0)
        cat(path);
    else
        return 0;
    return 1;
}
