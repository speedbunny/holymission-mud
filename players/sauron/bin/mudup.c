#include <sys_defs.h>

int main() {
    string sIP, *sTold;
    object oOb;
    
    sIP = query_ip_number(TP);
    sTold = ({});
 
    oOb = find_player("mangla");
    if(oOb && interactive(oOb)) {
        tell_object(oOb,
                    "Sauron tells you: My mud is up at: "+sIP+" 4242\n");
        oOb->setenv("REPLY", "sauron");
        sTold += ({"Mangla"});
    }

    oOb = find_player("nae");
    if(oOb && interactive(oOb)) {
        tell_object(oOb,
                    "Sauron tells you: My mud is up at: "+sIP+" 4242\n");
        oOb->setenv("REPLY", "sauron");
        sTold += ({"Nae"});
    }
 
    oOb = find_player("redsexy");
    if(oOb && interactive(oOb)) {
        tell_object(oOb,
                    "Sauron tells you: My mud is up at: "+sIP+" 4242\n");
        oOb->setenv("REPLY", "sauron");
        sTold += ({"Redsexy"});
    }
    
    if(sizeof(sTold))
        printf("You tell %s that your mud is up.\n",
               listArray(sTold)[0..<2]);
    else
        write("No-one online to tell.\n");
    return 1;
}
