
/* -------------------------------------------------------------------------
   The famous mousefur-boots (c) Whisky
   ------------------------------------------------------------------------- */

#define aa add_action   
#define TP this_player()

inherit "/obj/armour";
 
void reset(int flag) 
{
  ::reset(flag);
  if (flag == 0) 
  {
     set_name("boots");
     set_type("boots");
     set_ac(1);
     set_size(2);
    set_short("mousefur-boots");
     set_long("The boots from the evil mouse, "+
              "made for a hero who killed that beast.\n");
     set_value(60);
     set_weight(1);
  }
}

/* removed :whisky
void init()
{

    aa("do_go","",1);
  ::init();
}

int do_go(string arg)
{
  string *arr;
  string dir;

  switch(query_verb())
  {
     case "north":
     case "n":
     case "south":
     case "s":
     case "east":
     case "e":
     case "west":
     case "w":

       if (sizeof(environment(TP)->query_room("dest_dir")))
       {
           arr = environment(TP)->query_room("dest_dir");
           command(arr[0],TP);
           notify_fail("");
        }
        notify_fail("");
     default:
       notify_fail("");
   }
}

string short()
{
   init();
   return "mousefur-boots";
}     
  */
