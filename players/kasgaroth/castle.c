
#define DEST "/players/kasgaroth/workroom"

object quest;

int id(string str) 
{ 
    return str == "castle"; 
}

string short() 
{
    return "Kasgaroth's Cave";
}

void long() 
{
    write("Kasgaroth's Cave is scary.\n");
}

#if 0
void make_quest()
{
    quest = clone_object("obj/quest_obj");
    quest->set_name("generic_quest");
    quest->set_weight(1);
    quest->set_killing(3);
    quest->set_short_hint("Generic Short");
    quest->set_hint("Generic Long");
    quest->add_quest();
}
#endif

void reset(int flag) 
{
    if (!find_object("/players/kasgaroth/workroom"))
    {
	catch(call_other(DEST,"???"));
	move_object(this_object(),DEST);
    }

    else 
	move_object(this_object(), DEST);
}

