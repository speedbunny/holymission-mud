

/* rest_obj */

#define COMS ({"stand","say","help","who","score","look","rwhere","alias",\
               "look","l","whisper","smile","finger","attr"})


int id(string arg)
{
    return arg == "rest_obj";
}

int drop(string arg) 
{ 
   if (id(arg))
       return 1; 
   return 0;
}

int get(string arg)
{
    return 1;
}

int query_weight()
{
    return 0;
}


void init() 
{
  add_action("block_cmd","",1);
}

int block_cmd(string arg) 
{ 
    object env;

    env = environment();

    if (objectp(env) && env!=this_player())
        return 0;
    else if (member_array(query_verb(),COMS)!=-1)
    {
         return 0;
    }
    write("You are resting, type stand to finish.\n");
    return 1;
}



