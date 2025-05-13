
/* Coded by Tegerl, 28.3.1995 */
/* rooms/town/manu */
/* Exos - 05-01-97 a Few minor changes such as making do_move a status */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

int counter;

query_long()
{
    if (counter <= 0)
	return (    "You are in an armour manufactory. " +
	  "Everybody is busy here, everything is going fine. " +
	  "All workers here to their job in an excellent way. " +
	  "In a corner you can realize a man who sits at a table, "+
	  "getting pieces of iron from another table and another man "+
	  "hammers those pieces. You can see that the second table is far "+
	  "away from the man, maybe you should help him and move that table.\n" );

    return (    "You are in an armour manufactory. " +
      "Everybody is busy here, but nothing is going fine. " +
      "The whole manufactory is messed up. Someone must have " +
      "brought major discord in here.\n" );
}

void reset(int arg) 
{
    ::reset(arg);
    if (arg) return;

    set_light(1);
    short_desc="In an armour manufactory";
    long_desc="@@query_long@@";

    dest_dir=({
      "players/tegerl/jabberwocky/rooms/town/street5", "west",
    });

    items=({
      "manufactory","It is a very modern manufactory. Here are wheels, tables, iron and many workers",
      "wheels","Those wheels are used to keep the hammers in movement",
      "tables","There are many tables, and all are used by workers",
      "table","There are many tables, but that one is of interest, because he seems to be at the wrong place",
      "hammers","The workers use these hammers to make armours, but they also make an awful noise",
      "hammer","This hammer is used to make armours",
      "workers","These man are skilled armour makers",
      "worker","This man is a skilled armour maker",
    });

    smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
    ::reset(arg);
}

void init() {
    ::init();
    add_action("do_move","move");
}

status do_move(string str) {
    if (!(str=="table"))
    {
	write("Move what ?\n");
	return 1;
    }
    if (str=="table");
    {
	if (counter <=0)
	{
	    write("You move the table closer to that worker.\n");
	    write("But the worker wants to take the iron from where the table was before, \n");
	    write("and fails, so he moves his hand back. The other man hammers as usual, \n");
	    write("but the poor worker's hand. The poor man screams in agony and runs\n");
	    write("through the manufactory destroying everyting.\n");
	    write("In this desaster an old armour falls down and lands in front of your feet.\n");
	    say(this_player()->query_name()+" move the table closer to that worker.\n");
	    say("But the worker wants to take the iron from where the table was before, \n");
	    say("and fails, so he moves his hand back. The other man hammers as usual,\n");
	    say("but the poor worker's hand. The poor man screams in agony and runs\n");
	    say("through the manufactory destroying everyting.\n"); 
	    transfer(clone_object("/players/tegerl/jabberwocky/obj/oldarm"),(this_object()));
	    counter++;
	}
	else
	{
	    write("Everything in here is destroyed.\n");
	}
	return 1;
    }
}
