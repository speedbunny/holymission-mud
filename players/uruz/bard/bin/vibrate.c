#include "/players/trout/defs.h"


main (string str){
  object who, what;
  string person;

  	if(!str){
		write("Vibrate what?\n");
		return 1;
		}
   sscanf(str, "%s on %s", what, person);
	if(!what){
		write("Vibrate what?\n");
		return 1;
		}
       	if(!person){
		write("Vibrate "+what+" on who?\n");
		return 1;
		}
	call_out("_destruct", 3, what, person);
	who= present(person, ENV(TP()));
	say(person+"'s "+what+" begins to vibrate uncontrollably!\n");
     }


_destruct(object what, string person){
    object env, who, *ob, *ob1;
    int i, j, k;
	env= ENV(TP());
	ob= all_inventory(env);
	who= find_living(person);
	j= sizeof(ob);
	for(i=0; i<j; i++){
	     if(ob[i]->query_name()==person){
		    ob1= all_inventory(who);
		    k= sizeof(ob1);
		    for(i=0; i<k; i++){
			if(ob1[i]->query_name()==what){
			     destruct(ob1[i]);
			     write("You vibrate "+person+"'s "+what+" to "+
			     "pieces!\n");
			     return 1;
			}
		      }
	      }
	   }
    }
