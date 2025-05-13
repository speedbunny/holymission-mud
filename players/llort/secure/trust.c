inherit "room/room";
inherit "tools/tool";

string *trustees;

init()
{
   if(member_array(this_player()->query_real_name(),trustees)==-1)
   {
      write("NO WAY\n");
      move_object(this_player(),"/room/void");
      return;
   }
   {
        add_action("do_align","align");
        add_action("clear_room","clear");
        add_action("do_desc","desc");
        add_action("destroy_tool","destroy");
        add_action("do_don","don");
        add_action("do_doff","doff");
        add_action("do_dwho","dwho");
        add_action("do_net","net");
        add_action("do_man","man");
        add_action("shout_curse","noshout");
        add_action("do_objects","objects");
        add_action("do_show","show");
        add_action("do_where","where");
        add_action("do_scan","scan");
        add_action("do_i_dump","i_dump");
        add_action("do_i_mark","i_mark");
        add_action("do_i_mark","im");
        add_action("do_i_clone","i_clone");
        add_action("do_i_swap","i_swap");
        add_action("do_i_swap","isw");
        add_action("do_i_destruct","i_destruct");
        add_action("do_i_destruct","id");
        add_action("do_i_call","i_call");
        add_action("do_i_call","ic");
        add_action("do_i_more","i_more");
        add_action("do_i_move","i_move");
        add_action("do_i_move","imo");
        add_action("do_i_show","i_show");
        add_action("do_i_show","ish");
        add_action("do_snooptrace","snooptrace");
        add_action("do_snooptrace","sn");
        add_action("ih","ih");
        add_action("ir","ir");
        add_action("il","il");
        add_action("idl","idl");
        add_action("do_invent","I");
        add_action("ii","ii");
        add_action("ime","ime");
        add_action("do_i_clear","i_clear");
        add_action("do_i_clear","icl");
        add_action("do_i_who","i_who");
        add_action("do_i_stat","i_stat");
        add_action("do_i_stat","is");
        add_action("_upd","updir");
        add_action("_ld","ldir");
        add_action("help__","help");
  }
}

help__()
{
   ::long();
   return 1;
}

reset()
{
   set_light(1);
   trustees=({ "impatience","just","beardy","llort", "whisky", "herp", "tegerl" });  /* NEIN ! */
}

long()
{ write("You are trusted to use this room.\n"); }

short()
{ return "Trusted"; }

