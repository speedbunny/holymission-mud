

/* rest_obj */

#define COMS ({"stand","say","help","who","score","look","rwhere","alias",\
               "look","l","monk","mt","whisper","smile","finger","attr",\
               "mskills","monkey"})


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
  call_out("rest_ok",1);
}

void rest_ok()
{
   tell_object(environment(),"You start to move into the lotus position.\n");
   say(environment()->query_name()+"starts to move into the lotus position.\n",
       environment());
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



