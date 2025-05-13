#include "/players/sauron/include/include.h"
#include <sys_bin.h>

int main(string sStr) {
    string sErr, sFile, sCode, sVerb;
    int    iEval, iSpace;
    object oOb;
    mixed  xRes;

    sVerb = query_verb();

    sFile="/players/"+RNAME(TP)+"/parse_tmp.c";
    if(oOb=find_object(sFile))
        destruct(oOb);
    if(file_size(sFile))
        rm(sFile);
    sCode = "\
#include \"/players/sauron/include/include.h\"\n\
\n\
object oMark, oSpare, oLast, oParse;\n\
\n\
mixed parseIt() {\n\
    "+sStr+";\n\
}\n\
\n\
void reset() {\n\
    oMark  = TP->queryenv(\"I_MARK\");\n\
    oSpare = TP->queryenv(\"I_SPARE\");\n\
    oLast  = TP->queryenv(\"I_LAST\");\n\
    oParse = TP->queryenv(\"PARSE\");\n\
}\n";
    write_file(sFile, sCode);
    if(catch(sFile->aLoadFun())) {
        printf("\n%s: Error in loading object '%s'.\n%s",
               sVerb, sFile, sCode);
//        (NEWWIZ_BIN+"debug")->main(0);
    }
    else {
        oOb = find_object(sFile);
        if(!oOb)
            printf("%s: Object for '%s' not found!\n", sVerb, sFile);
        else if(sVerb == "eval") {
            iEval = get_eval_cost();
            if(sErr = catch(xRes = (mixed)oOb->parseIt()))
                printf("eval: Error in parsing code.\n%s\n", sErr);
            else {
                iEval -= get_eval_cost();
                printf("eval: Returned: %O\n      Eval: %d\n",
                       xRes, iEval);
                if(objectp(xRes))
                    TP->setenv("PARSE", (object)xRes);
                else
                    TP->setenv("PARSE", (object)0);
            }
        }
        else {
            if(sErr = catch(xRes = (mixed)oOb->parseIt()))
                printf("parse: Error in parsing code.\n%s\n", sErr);
            else {
                printf("parse: Returned: %O\n", xRes);
                if(objectp(xRes))
                    TP->setenv("PARSE", (object)xRes);
                else
                    TP->setenv("PARSE", (object)0);
            }
        }
    }
    if(oOb)
        destruct(oOb);
    if(file_size(sFile))
        rm(sFile);
    return 1;
}
