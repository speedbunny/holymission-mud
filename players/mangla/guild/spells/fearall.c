#include "/players/mangla/defs.h"
#include "/sys/levels.h"

/******** FEARALL Scares all opponents out of the room.
               Possibility of legend level to scare opponents stiff.
*********/

int main() {
    int     i, sz;
    object *people;

    people = all_inventory( ENV( TP ) );
    sz= sizeof(people)-1;

    for( i=sz; i>=0; i-- ) 
        if( people[i] == TP || !living(people[i]) || strlen(people[i]->RNAME) == 0) {
            write(people[i]); write("\n");
            people=del_array(people, i);
        }

    if( !sizeof(people) ) {
	write("Who do you want to fear? You are the only living here!\n");
        return 1;
    }

    write("You concentrate your Force and say some words.\n");
    say(TP->NAME+" speaks some strange words and waves with a hand.\n");

    for( i=0; i<sizeof(people); i++ ) {
        if(people[i]->query_guild()==4 && people[i]->LEVEL>TP->LEVEL-2) {
            write("The mental force of "+people[i]->NAME + " is higher "+
		  "or at least equal to yours.\nYou cannot fear "+ 
		  people[i]->OBJ + ".\n");
            TELL(people[i], TP->NAME + " tried to fear you.\n");
        }
        else if( people[i]->WIS-20 > (TP->WIS + TP->CHA))
            write(people[i]->NAME + " is to wise to fall for that.\n");
        else if(people[i]->query_wimpy() < 0) 
            write( people[i]->NAME+" is too foolhardy to be afraid "+
                   "of you.\n");
	else {
            TELL(people[i], "As you look up to " +TP->NAME+ " you get an "+
             "unusual feeling.\nYour hands begin to sweat.\nYou panic.\n");
            if(TP->query_legend_level() && !people[i]->query_immortal() 
			&& random(2)) {
                write("You fear " +people[i]+ " so bad that it freezes in "+
		      "fear.\n");
                people[i]->hold(TP,30);
            }
            people[i]->run_away();
            if( ENV(people[i]) == ENV(TP) ) {
                write(capitalize(people[i]->NAME)+" did not flee.\n");
            }
	}
    }
    return 1;
}
