inherit "room/room";

#include "/players/darastor/include/seaside.h"

#define CLOSED "closed"
#define OPEN   "open"
#define DRAWER_STRING ({"top","middle","bottom"})

mapping drawer_map;

/*
The next method is a background method for the drawers
*/

int drawer_exists(string drawer_name)
{
    return member(drawer_map,drawer_name);
}

/*
The next methods are the interface methods for the drawers
*/

int query_open(string drawer_name)
{
    return (drawer_map[drawer_name]==OPEN);
}

int query_any_drawer_open()
{
    int i, total;
    total=0;
    for(i=0;i<3;++i)
        if(drawer_map[DRAWER_STRING[i]]==OPEN)
            total+=1;
    return total;
}

/*
The next methods are description methods for items whose desciptions may
change depending on whether the drawers are open or closed
*/

string drawer_desc(string drawer)
{
    string description;
    description="The "+drawer+" drawer is "+drawer_map[drawer];
    if(drawer_map[drawer]==OPEN)
        description=description+". Inside you can see a lot of clothes";
    return description;
}

string clothes_desc()
{
    if(!query_any_drawer_open())
        return("You can't see any clothes here");
    else
        return("The clothes look quite cheap and ordinary");
}

/*
Next methods are add_actions for the actions defined in the init routine
*/

int _open(string str)
{
    string which_drawer;
    
    if(!str)
    {
        notify_fail("Open what?\n");
        return 0;
    }
    
    if(str=="drawer")
    {
        tell_object(TP,"Which drawer do you wish to open?\n");
        return 1;
    }
    
    if(sscanf(str,"%s drawer",which_drawer)==1)
    {
        if(!drawer_exists(which_drawer))
        {
            notify_fail("There is no "+which_drawer+" drawer here.\n");
            return 0;
        }
        
        if(drawer_map[which_drawer]==OPEN)
        {
            notify_fail("The "+which_drawer+" drawer is already open.\n");
            return 0;
        }
        
        tell_object(TP,"You open the "+which_drawer+" drawer to reveal a "+
          "load of clothes.\n");
        say(CNAME+" opens the "+which_drawer+" drawer.\n",TP);
        drawer_map[which_drawer]=OPEN;
        return 1;
    }
    
    notify_fail("Open what?\n");
    return 0;
}

int _close(string str)
{
    int i;
    string which_drawer;
    
    if(!str)
    {
        notify_fail("Open what?\n");
        return 0;
    }
    
    if(str=="drawer")
    {
        if(!query_any_drawer_open())
        {
            tell_object(TP,"None of the drawers are open.\n");
            return 1;
        }
        
        if(query_any_drawer_open()==1)
         {
            for(i=0;i<3;i++)
                drawer_map[DRAWER_STRING[i]]=CLOSED;
            tell_object(TP,"You close the drawer.\n");
            say(CNAME+" closes the drawer.\n",TP);
            return 1;
        }
	    
        notify_fail("Which drawer do you wish to close?\n");
        return 0;
    }
    
    if(sscanf(str,"%s drawer",which_drawer)==1)
    {
        if(!drawer_exists(which_drawer))
        {
            notify_fail("There is no "+which_drawer+" drawer here.\n");
            return 0;
        }
        
        if(drawer_map[which_drawer]==CLOSED)
        {
            notify_fail("The "+which_drawer+" drawer is not open.\n");
            return 0;
        }
        
        tell_object(TP,"You close the "+which_drawer+" drawer.\n");
        say(CNAME+" closes the "+which_drawer+" drawer.\n",TP);
        drawer_map[which_drawer]=CLOSED;
        return 1;
    }
    
    notify_fail("Close what?\n");
    return 0;
}

/*
The next methods are the overridden reset and init methods from /room/room
*/

void reset(int arg)
{
    int i;
    
    ::reset(arg);
    
    if(!arg)
    {
        drawer_map=([
          "top":CLOSED,
          "middle":CLOSED,
          "bottom":CLOSED
        ]);
    }
    else
    {
        for(i=0;i<3;i++)
            drawer_map[DRAWER_STRING[i]]=CLOSED;
    }
}

void init()
{
    ::init();
    add_action("_open","open");
    add_action("_close","close");
}
