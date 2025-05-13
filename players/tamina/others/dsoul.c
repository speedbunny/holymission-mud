/* Coded by Meecham@HolyMission Summer '94 */
/* Meecham&Topaz : changed hail to maelstrom */

#include "/players/meecham/guild/g_def.h"
#include "/players/meecham/guild/spell_cost.h"
#define GM "guild/master"

object tree,shad;
int gd;

id(str) { return str=="druidsoul" || str=="guildsoul"; }

drop() { return 1; }
get() { return 1; }

reset(arg)
{
  if(arg) return;
  gd=GM->query_number("druid");
}

init()
{
  TP->set_incognito(0);
  add_action("no_way","incognito");
  add_action("guild_txt","help");
  add_action("spell_txt","dhelp");
  add_action("bolt_spell","bolt");
  add_action("move_it","rupture");
  add_action("change_attack","surge");
  add_action("teleport_fnc","send");
  add_action("bark","barkskin");
  add_action("stop_att","raise");
  add_action("grow_fnc","grow");
  add_action("go_back","gotree");
  add_action("dest_tree","absorb");
  add_action("druid_line","druid");
  add_action("guild_emote","dr");
  add_action("check","appraise");
  add_action("helper","form");
  add_action("dest_el","rid");
  add_action("goguild","breeze");
  add_action("earthquake","quake");
  add_action("hail_storm","maelstrom");
  add_action("not","missile");
  add_action("not","shock");
  add_action("not","fireball");
}

not()
{ return 0; }

guild_changes()
{
  if(shad)
    shad->dest_shad();
  return 1;
}

guild_txt(str)
{
    if((!str) || (str !="guild")) return 0;
    cat("/"+PM+"guild/doc/help.txt");
    return 1;
}

spell_txt(str)
{ return (G+"help.c")->help(str); }

no_way()
{
    printf("Sorry, druids cannot be incognito.\n");
    return 1;
}

bolt_spell(str)
{
  CHK_GHOST;
    CHK_LVL(20);
    CHK_BUSY;
    CHK_SP(bolt_cost);
    BUSY;
    return (G+"bolt.c")->bolt(str,bolt_cost);
}

move_it(str)
{
  CHK_GHOST;
    CHK_LVL(10);
    CHK_SP(rupture_cost);
    return (G+"rupture.c")->move_it(str,rupture_cost);
}

change_attack()
{
  CHK_GHOST;
    CHK_LVL(10);
    CHK_SP(surge_cost);
    return (G+"surge.c")->change_attack(surge_cost);
}

teleport_fnc(str)
{
  CHK_GHOST;
    CHK_LVL(25);
    CHK_SP(send_cost);
    return (G+"teleport.c")->teleport_fnc(str,send_cost);
}

bark()
{
  CHK_GHOST;
    CHK_LVL(12);
    CHK_SP(barkskin_cost);
    shad=CO(G+"bs.c");
    shad->start_shadow(TP,barkskin_cost);
    return 1;
}

stop_att(str)
{
  CHK_GHOST;
    CHK_LVL(8);
    CHK_SP(raise_vine_cost);
    return (G+"calm.c")->stop_att(str,raise_vine_cost);
}

grow_fnc(str)
{
  CHK_GHOST;
    CHK_LVL(15);
    CHK_SP(tree_cost);
    tree=(G+"tree.c")->grow_fnc(str,tree_cost,tree);
    return 1;
}

go_back()
{
  CHK_GHOST;
    CHK_LVL(15);
    CHK_SP(gotree_cost);
    return (G+"tree.c")->go_back(gotree_cost,tree);
}

dest_tree(str)
{ return (G+"tree.c")->dest_tree(str,tree); }

druid_line(str)
{
    if(!str)
    {
	printf("Druids currently wandering within Holy Mission:\n\n");
	return "/sys/chatd"->print_line(2);
    }
    return TP->guild_line(str);
}

guild_emote(str)
{ 
  if(!str)
  {
    printf("Emote what?\n");
    return 1;
  }
  return "/sys/chatd"->do_chat(gd,"<* Druid *> "+TPN+" "+str+"\n"); 
}

check(str)
{
    CHK_SP(appraise_cost);
    return (G+"appraise.c")->appraise(str,appraise_cost);
}

helper(str)
{
  CHK_GHOST;
    CHK_LVL(8);
    CHK_SP(form_earth_cost);
    return (G+"form.c")->form(str,form_earth_cost);
}

dest_el(str)
{
    if(str) return 0;
    (G+"form.c")->dest_me();
    return 1;
}

goguild()
{
  CHK_GHOST;
    CHK_LVL(5);
    CHK_SP(goguild_cost);
    return (G+"goguild.c")->goguild(goguild_cost);
}
earthquake(str)
{
  CHK_GHOST;
    CHK_LVL(5);
    CHK_BUSY;
    CHK_SP(quake_cost);
    BUSY;
    return (G+"quake.c")->quake(str,quake_cost);
}

hail_storm(str)
{
  CHK_GHOST;
    CHK_LVL(12);
    CHK_BUSY;
    CHK_SP(hail_cost);
    BUSY;
    return (G+"hail.c")->hail(str,hail_cost);
}
