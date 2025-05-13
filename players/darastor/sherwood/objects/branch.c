/* Originally by Goldsun, updated by Darastor */
/* Because property implementation is screwed up at the moment
   this implements test for has_fire properly for objects and rooms */

inherit "/obj/weapon";

#include "/players/darastor/include/sherwood.h"

int how_long;

int has_fire_func(object ob)
{
    return (ob->query_property("has_fire")!=-1);
}

void reset(int arg)
{
    ::reset(arg);

    if (!arg)
    {
        how_long = 800;  /* time */
        set_name("branch");
        set_class(1);
        set_long("A branch from a large heavy tree.\n");
        set_weight(1);
        /* at create make sure it is extinguished :) */
        add_property("has_fire",0);
    }
}

/* CHECK NEXT METHOD */

string short()
{
    if (query_property("has_fire")!=-1)
        return ::short()+" [lighted]";
    else
        return ::short();
}

void init()
{
    ::init();
    add_action("_light","light");
    add_action("_extinguish","extinguish"); 
}

int _light(string str)
{
    object *objects_with_fire;

    if(!str)
    {
        notify_fail("Light what?\n");
        return 0;
    }

    if (!id(str))
        return 0;
        
    if (query_property("has_fire")!=-1)
    {
      tell_object(TP,"Your branch is already lit.\n");
      return 1;
    }
    
    objects_with_fire=filter_objects(all_inventory(TP),"has_fire_func",TO);
        
    if ((!sizeof(objects_with_fire))&&
      (!environment(TP)->query_property("has_fire")))
    {
        notify_fail("You need a source of fire to light your branch.\n");
        return 0;
    }
    
    tell_object(TP,"You light your branch.\n");
    say(CNAME+" lights a branch.\n");
        
    set_class(4);
    set_light(1);
    set_alt_name("lighted_torch");
    
    add_property("has_fire",1);
    call_out("end_light",how_long);
    return 1;
}

int _extinguish(string str)
{
    if(!str)
    {
        notify_fail("Extinguish what?\n");
        return 0;
    }
    
    if (!id(str)||query_property("has_fire")!=-1)
        return 0;

    tell_object(TP,"You extinguish your branch.\n");
    say(CNAME+" extinguished a branch.\n");
    how_long = find_call_out("end_light");
    remove_call_out("end_light");
    add_property("has_fire",0);
    
    set_class(1);
    set_light(0);
    set_alt_name("");
    return 1;
}

void end_light()
{
    object owner;

    if((living(owner=environment()))&&(interactive(owner)))
    {
        tell_object(owner,"Your branch burns out and crumbles to "+
          "ashes.\n");
    }
    destruct(TO);
}
    
    
