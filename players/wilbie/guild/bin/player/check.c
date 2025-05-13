#include <sys_defs.h>

int main(string sStr) {
    if(!sStr || sStr == "") {
        int    i;
        object *oaArr;
        
        oaArr = (object *)TP->query_bad_armours();
        if(sizeof(oaArr)) {
            write("You feel that the following items are hindering your \
abilities:\n\n");
            for(i = 0; i < sizeof(oaArr); i++)
                printf("%s\n", (string)oaArr[i]->NAME);
        }
        else
            write("You don't feel that anything is hindering your \
abilities.\n");
    }
    else {
        string *saArr;
        int    iMine;
        object oOb;
         
        oOb = present(sStr, TP);
        if(!oOb)
            oOb = present(sStr, ENV(TP));
        else
            iMine = 1;
 
        if(!oOb)
            printf("Could not find anything matching '%s' to check.\n",
                   sStr);
        else if(!oOb->query_armour())
            printf("You couldn't wear the %s anyway, so there's not much \
point in checking it is there? :)\n", sStr);
        else {
            saArr = (string *)TP->query_ok_armours();
            if((int)oOb->armour_class() > 0 &&
               !oOb->query_monk_wear() && saArr &&
               member_array((string)oOb->query_type(), saArr) == -1) {
                if(iMine)
                    printf("You feel that your %s would hinder your monk \
abilities.\n", sStr);
                else
                    printf("You feel that the %s would hinder your monk \
abilities.\n", sStr);
            }
            else if(iMine)
                printf("You feel that your %s would not hinder your \
monk abilities.\n", sStr);
            else
                printf("You feel that the %s would not hinder your \
monk abilities.\n", sStr);
        }
    }
    return 1;
}
