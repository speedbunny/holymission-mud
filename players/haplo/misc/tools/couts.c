
//    From the Nightmare mudlib
//    Coded by Valodin on Feb 4, 1993

// Wow this works fine in HM too :))) (just a few alternations were needed)
// Leslie@HM (from Leslie@CD)
#include <std.h>
inherit "/obj/thing";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Callouts tool");
    set_short("The call_out_info tool");
    set_alias("tool");
    set_long("This is a tool, that enables you to see all pending call_outs. Just type 'callouts' to see them.");
    set_weight(0);
    set_value(0);
}


void init() {
    if(!(this_player()->query_lord())) return destruct(this_object());
    add_action("cmd_callouts", "callouts");
    add_action("help", "help");
}


int cmd_callouts(string str)
{
    mixed *crap;
    mixed *element;
    object ob;
    string func, filename, trash, spaces;
    int i, j, delay;
    mixed args;
    string printing_crap;

    crap = call_out_info();

    if(!sizeof(crap))
    {
        write("There are no call_outs right now.\n");
        return 1;
    }

    write("Object                               Function  Delay  Arguments\n" +
      "------                               --------  -----  ---------\n");

    for(i = 0; i < sizeof(crap); i++)
    {
        element = crap[i];
        if(sizeof(element) != 4)
        {
            write("Size problem " + sizeof(element) + " " + element[0] + " \n");
            continue;
        }
        ob = (object)element[0];
        func = (string)element[1];
        delay = (int)element[2];
        args  = element[3];
        filename = file_name(ob);
        if(strlen(filename) > 35)
        {
            while(strlen(filename) > 34)
                sscanf(filename, "%s/%s", trash, filename);
            filename = "~" + filename;
        }
        spaces = "  ";
        for(j = strlen(filename); j < 35; j++)
            spaces += " ";
        printing_crap = filename + spaces + func + "  "  + delay;
        if(sizeof(args))
            for(j = 0; j < sizeof(args); j++)
                if(sizeof(args[j]))
                    printing_crap += "  <ARRAY:" + sizeof(args[j]);
                else
                if(objectp(args[j]))
                    if(args[j]->is_player())
                        printing_crap += "  " + args[j]->query_cap_name();
                    else
                    {
                        filename = file_name(args[j]);
                        if(strlen(filename) > 25)
                        {
                            while(strlen(filename) > 24)
                                sscanf(filename, "%s/%s", trash, filename);
                            filename = "~" + filename;
                        }
                        printing_crap += "  " + filename;
                    }
                else
                    printing_crap += "  " + (string)args[j];
        else
        if(objectp(args))
            if(args->is_player())
                printing_crap += "  " + args->query_cap_name();
            else
            {
                filename = file_name(args);
                if(strlen(filename) > 25)
                {
                    while(strlen(filename) > 24)
                        sscanf(filename, "%s/%s", trash, filename);
                    filename = "~" + filename;
                }
                printing_crap += "  " + filename;
            }
        else
            printing_crap += "  " + (string)args;
        write(printing_crap+"\n");
    }
    return 1;
}

int help(string str)
{
    if(str != "callouts") return 0;
    write("Command: callouts\n\n" +
      "This command lists all the call_outs on the mud.\n" +
      "See man: call_out_info\n"+
      "See also: cache, mstatus, netstat, fdinfo, opcprof, dumpallobj\n"+
      "" );
    return 1;
}
