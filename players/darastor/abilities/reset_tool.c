inherit "/obj/treasure";

#include "/players/darastor/abilities/resethere.c"

/*
int main(string str)
{

    int resetArg;
    int envPathSize;
    object env;
    string envFileName;
    
    string *envFilePath;

    if(!str)
        return 0;
        
    if((sscanf(str,"%d",resetArg)!=1)||((resetArg!=0)&&(resetArg!=1)))
    {
        notify_fail("Invalid argument to reset.\n");
        return 0;
    }
            
    envFileName=file_name(env=environment(this_player()));
    
    if(envFileName)
    {
        envFilePath=explode(envFileName,"/");
        envPathSize=sizeof(envFilePath);
        if((envPathSize>1)&&(envFilePath[1]==
          (string)(this_player()->query_real_name())))
        {
            env->reset(resetArg);
            tell_object(this_player(),"Called reset "+to_string(resetArg)+"\n");
            say(capitalize(this_player()->query_name())+"called "+
              "reset with arg "+resetArg+".\n",this_player());
            return 1;
        }
        else
        {
            notify_fail("You can only reset your own rooms.\n");
            return 0;
        }
    }
    else
    {
        notify_fail("Could not get environment file name.\n");
        return 0;
    }
}
*/

void reset(int arg)
{
    ::reset(arg);
    set_name("rtool");
    set_alias("reset tool");
    set_value(0);
    set_short("Darastor's reset tool");
    set_long("Darastor is using this tool to test the resethere command.\n");
}

void init()
{
    ::init();
    add_action("main","resethere");
}
