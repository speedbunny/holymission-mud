
/* nono-stone */

inherit "/obj/treasure";

void reset(int flag)
{
     ::reset(flag);

     if (flag == 0)
     {
        set_name("nono stone");
        set_alias("stone");
        set_short(query_name());
        set_long("A dull gray stone with the inscription:\n\n"+
                 "            NEVER SAY NO !             \n");
        set_weight(1);
        set_value(900);
        enable_commands();
     }
}

int get()
{
  if (this_player()->query_player())
      set_heart_beat(1);
   return 1;
}

int drop()
{
   set_heart_beat(0);
   return 0;
} 

void heart_beat()
{
   if (environment())
       environment()->heal_self(1);
}

void init()
{
   if (environment() && environment()==this_player())
       add_action("do_say","say");
     ::init();
}

int do_react(string arg)
{
   mixed x;
   int i;
   object tp;
 
    x = crypt(arg,0);
    i = random(5);
    tp = this_player();

    write("Nono Stone says: "+to_string(x)+"\n");
    say(tp->query_name()+
        "'s Nono Stone says: "+to_string(x)+"\n",tp);

    switch(i)
    {
      case 0:
       tp->move_player(
       "in a cloud of mushrooms#room/orc_treasure");
      break;
      case 1:
       tp->move_player(
       "in a cloud of mushrooms#players/whisky/hole/room/h17");
      break;
      case 2:
       tp->move_player(
       "in a cloud of mushrooms#players/llort/guild/tower/store_room");
      break;
      case 3:
       tp->move_player(
       "in a cloud of mushrooms#players/whisky/seaworld/room/sw25");
      break;
      default:
       tp->move_player(
       "in a cloud of mushrooms#players/whisky/quest/room/forest/f83");
      break;
     }
   write("Your stone vanishes !\n");
   destruct(this_object());
   return 1;
}

int do_say(string arg)
{
    if (arg && strstr(arg,"no",0)!=-1)
        do_react(arg);
    return 0;
}



/* nono-stone */

inherit "/obj/treasure";

void reset(int flag)
{
     ::reset(flag);

     if (flag == 0)
     {
        set_name("nono stone");
        set_alias("stone");
        set_short(query_name());
        set_long("A dull gray stone with the inscription:\n\n"+
                 "            NEVER SAY NO !             \n");
        set_weight(1);
        set_value(900);
        enable_commands();
     }
}

int get()
{
  if (this_player()->query_player())
      set_heart_beat(1);
   return 1;
}

int drop()
{
   set_heart_beat(0);
   return 0;
} 

void heart_beat()
{
   if (environment())
       environment()->heal_self(1);
}

void init()
{
   if (environment() && environment()==this_player())
       add_action("do_say","say");
     ::init();
}

int do_react(string arg)
{
   mixed x;
   int i;
   object tp;
 
    x = crypt(arg,0);
    i = random(5);
    tp = this_player();

    write("Nono Stone says: "+to_string(x)+"\n");
    say(tp->query_name()+
        "'s Nono Stone says: "+to_string(x)+"\n",tp);

    switch(i)
    {
      case 0:
       tp->move_player(
       "in a cloud of mushrooms#room/orc_treasure");
      break;
      case 1:
       tp->move_player(
       "in a cloud of mushrooms#players/whisky/hole/room/h17");
      break;
      case 2:
       tp->move_player(
       "in a cloud of mushrooms#players/llort/guild/tower/store_room");
      break;
      case 3:
       tp->move_player(
       "in a cloud of mushrooms#players/whisky/seaworld/room/sw25");
      break;
      default:
       tp->move_player(
       "in a cloud of mushrooms#players/whisky/quest/room/forest/f83");
      break;
     }
   write("Your stone vanishes !\n");
   destruct(this_object());
   return 1;
}

int do_say(string arg)
{
    if (arg && strstr(arg,"no",0)!=-1)
        do_react(arg);
    return 0;
}


