
/* branch */

#define TP this_player()
#define TPN TP->query_name()
#define E   environment
#define S(x) say(x)
#define W(x) write(x)
#define A(x,y)  add_action(x,y)

inherit "/obj/weapon";

int how_long, lighted;

void reset(int flag)
{
     ::reset(flag);

     if (flag == 0)
     {
        how_long = 800;  /* time */
        set_name("branch");
        set_class(1);
	set_long("A branch from a large heavy tree.\n");
        set_weight(1);
     }
}

string short()
{
    if (lighted && wielded == 1) 
        return query_name()+" [lighted && wielded]";
    else if (lighted)
        return query_name()+" [lighted]";
    else if (wielded == 1)
        return query_name()+" [wielded in both hands]";
    else 
       return query_name()+"";
}

void init()
{
     ::init();
     A("do_li","light");
     A("do_ex","extinguish"); 
}

int do_li(string arg)
{
    if (!id(arg)) return 0;
    else if (lighted == 1)
    {
      W("Your branch is already lighted.\n");
      return 1;
    }
    else if (!present("lighted_torch",TP) && !E(TP)->query_property("has_fire"))
    {
      W("You need a light source to light your branch.\n");
      return 1;
    }
    W("You light your branch.\n");
    S(TPN+" lights a branch.\n");
    lighted = 1;
    set_class(4);
    set_light(1);
    set_alt_name("lighted_torch");
    call_out("end_light",how_long);
 return 1;
}

int do_ex(string arg)
{
    if (!id(arg) || lighted == 0) return 0;
    else if (lighted == 0)
    {
      W("Your branch is already extinguished.\n");
      return 1;
    }
    W("You extinguish your branch.\n");
    S(TPN+" extinguished a branch.\n");
    how_long = find_call_out("end_light");
    remove_call_out("end_light");
    lighted = 0;
    set_class(1);
    set_light(0);
    set_alt_name("");
    return 1;
}

void end_light()
{
   W("Your branch is burned out and crumles to ashes.\n");
   destruct(this_object());
}
    
    
