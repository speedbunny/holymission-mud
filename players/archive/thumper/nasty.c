inherit "room/room";

int test;

void reset(int arg)
{
 ::reset(arg);
 if(arg) return;
 set_light(1);
 short_desc = "main room short.@@_warning@@";
 long_desc  = "main room long.@@_warning@@\n";
}

string _warning() 
{
 string strval;
 if (!test) 
   {
    test=1;
    this_player()->reduce_hit_point(45);
    strval="You just stepped into something and stuff\n";
   }
 else strval=""; 
 return strval;
} 

void init()
{
 test=0;
 ::init();
}
