inherit "obj/treasure";

#define TO this_object()
#define NUMBERS ({1,"one",2,"two",3,"three",4,"four",5,"five",6,"six",7,"seven",8,\
                  "eight",9,"nine",10,"ten",\
		  11,"eleven",12,"twelve",13,"thirteen"})


object mist_of_whom;

reset( arg )
{
   if ( arg ) return;
  set_name("mist");
  set_alias("mist");
  set_long("A mist. Its number is 210195\n");
}

string verb(int i){
int is;
 if (member_array(i,NUMBERS)==-1) return "many";
 is= member_array(i,NUMBERS);
 return NUMBERS[is+1];

}

int show_this(){
string *exit, msg;
object *thing;
int i,j, size;

    if (!objectp(mist_of_whom)) return 0;
    environment(TO)->long();
    thing= ({});
    thing= all_inventory(environment(TO));
    exit = allocate(sizeof(thing));
    j=0;
    for(i=0;i<sizeof(thing);i++)
     if ( thing[i] != TO )
     {
	  exit[j]=thing[i]->short();
          j++;
     }
    for(i=0;i<j-1;i++)
     tell_object(mist_of_whom, exit[i]+"\n");
    if (j>1) tell_object(mist_of_whom,exit[j-1]+
         " are here.\n");
    if (j==1) tell_object(mist_of_whom,exit[j-1]+
	 " is here.\n");
  return 1;
 }

void set_mist_of_whom(object s){ mist_of_whom=s; }


mover(dest){
string *exit;
string dir;

    if (!dest){
     dest=query_verb();
    }
    exit=environment(TO)->query_room("dest_dir");
    if (!exit) return 0;
    if (member_array(dest,exit) == -1) return 0;
    dir=exit[member_array(dest,exit)-1];
    move_object(TO,dir);
    show_this();
    return 1;
}


catch_tell(str){
  tell_object(mist_of_whom,str);
  return 1;
}
