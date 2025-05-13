  /* finally a weapon for the monksguild : with malus anyone can wield it */
  /* value lowered because of newbies getting it */

inherit "/obj/weapon";


void reset(int flag)
{
     if (flag == 0)
     {
        set_name("nunchaku");
        set_alias("oaken nunchaku");
        set_long(
        "Two short, oakwooden sticks connected to an iron chain.\n");
        set_weight(1);
        set_class(4);
        set_type(2);
        set_value(90);
        set_hit_func(this_object());
     }
}

string short()
{
   if (query_wielded())
       return "An oaken nunchaku [wielded]";
   return "An oaken nunchaku";
}

int weapon_hit(object ob)
{
    int hit;
    if (this_player()->query_guild()==7)
        hit =  this_player()->query_dex()/3;
    else 
        hit = this_player()->query_dex() / 5;

    hit = 2 * hit;

   /* critical */
   if (random(200) <= this_player()->query_dex())
   {
    write(
    "Clack, you wildly swing your nunchaku against "+ob->query_name()+"\n");
    say(
    "Clack, "+this_player()->query_name()+" wildly swings "+
     this_player()->query_possessive()+" nunchaku against "+
     ob->query_name()+"\n",ob,this_player());
    tell_object(ob,this_player()->query_name()+" swings "+
    this_player()->query_possessive()+" nunchaku against you !\n");

    return (hit);
  }
    return (random(hit));
}     

int no_clear()
{
   return 1;
}
 void init()
 {
    ::init();
}
int query_monk_weapon() { return 1; }
