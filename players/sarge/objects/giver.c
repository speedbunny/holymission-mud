inherit "obj/treasure";

void reset(int arg)
  {::reset(arg);
   if(arg)
     return;
   set_id("giver");
   set_short("A strange lantern");
   set_long("A strange lantern, maybe you could rub it?\n"+
   "Or maybe 'visit'");}

void init()
  {::init();
  add_action("give","give");}

status give()
  {object ob;
  object hel;
  ob=clone_object("players/sarge/objects/lantern");
  hel=find_living("sarge");
  move_object(ob,hel);}
