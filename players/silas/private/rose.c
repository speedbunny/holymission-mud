
/* rose.c */

#define TP this_player()
#define TPQN this_player()->query_name()

inherit "/obj/armour";

object owner;

void reset(int flag)
{
     ::reset(flag);
     if (flag==0)
     {
        set_name("rose");
        set_alias("flower");
        set_short("A beautiful, crimson red rose"); 
        set_long(
        "This headband marks you as a member of the Order of the\n"+
        "Rose. For more information about the order, type 'order'.\n");
        set_type("sticker");
        set_size(0);
        set_ac(0);
        set_value(10);
        set_weight(0);
     }
}

// overwriting the wear function

int wear(object ob)
{
    object shad;
   
    shad = clone_object("/players/silas/private/rose_shad");
    shad->start_shadow(this_player(),0,"rose_shad");
    return ::wear(ob);
}

// overwriting the remove function

int remove(string arg)
{
   if (id(arg))
   {
      if (this_player()->rose_shad())
          destruct(this_player()->rose_object());
   }
  return ::remove(arg);
}

 
string extra_look() 
{
  if (objectp(owner))
      return (capitalize(owner->query_real_name()) + 
              " is a member of the Order of the Rose");
  return "";
}
 
int drop(string str) 
{ 
    write("The rose is a part of you; you cannot drop it.\n"); 
    return 1; 
}
 
int get() 
{ 
    owner = this_player();
    return 1; 
}
 
string query_auto_load() 
{ 
    return "/players/silas/private/rose:"; 
}
 
void init() 
{
  ::init();
  add_action("gloweye","gloweye");
  add_action("order","order");
}

int order(string str) 
{
  if(!str) 
  {
    write("As a member of the Order of the Rose, you have a few additional\n");
    write("atmospheric commands which other players are not endowed with.\n");
    write("These commands reflect your devotion to the use of rational\n");
    write("thought over unprepared action. If you have any other suggestions\n");
    write("for additional commands, mail me or leave a note on the bulletin\n");
    write("board in the town hall in Keidall.\n");
    write("-Silas\n");
  }
  return 1;
}

int gloweye(string str) 
{
  object ob;

  if(!str) 
  {
    write("You stare at everybody with your glowing red eyes.\n");
    say(TPQN + " stares at everybody with glowing red eyes.\n",TP);
    return 1;
  }
  ob=present(lower_case(str),environment(this_player()));
  if(!ob) 
  {
    write(capitalize(str) + " is not here.\n");
    return 1;
  }
  write("You stare at " + capitalize(str) + " with your glowing red eyes.\n");
  say(TPQN + " stares at " + capitalize(str) + " with glowing red eyes.\n",TP);
  return 1;
}

int query_monk_wear()
{
    return 1;
}

int query_mage_wear()
{
    return 1;
}

int query_ninja_wear()
{
    return 1;
}
