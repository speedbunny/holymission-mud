
/* disease 

EXAMPLE:

inherit "/players/whisky/obj/disease";

  void reset(int flag)
  {
     if (flag==0)
     {
   * the id of the flu can be called by present
         set_id("whisky_flu");
   * the extra look of the player if she caught the flu
         set_elook("is sweting and has red cheeks");
   * the art of the disease
         set_art("flu");
   * the message when the disease ends
         set_dmess("You feel better");
   * the message when the disease starts
         set_bmess("You caught a flu");
   * the messages when the disease is broken out to the player
         set_mmess(  
               ({"You shiver unconfortably",
                 "You feel really hot",
                 "Swet is driping down your skin",
                  "You breath hard"}));
   * the messages when the disease is broken out to the environment 
         set_omess( 
               ({"shivers unconfortably",
                 "cheeks are burning",
                 "is sweating",
                 "breathes hard"}));
    * the maximum timeintervall the messages are called as the disease fun 
         set_mtime(200);
    * the amount of time intervalls it is called
         set_delay(4);
    * the immunity to disease a player gets when the disease ends up
         set_imm(8);
    * the chance to infect a player in the environment
         set_cia(10);
    * the filename of your object 
         set_file("/players/whisky/obj/disease");
     }
}

    * this function can be used to  add effcts to the disease 
      object. The counter is the counter for the number of 
      messages a player gets. For example if mmess[i] and 
      i > 1 then the player gets ever a hit of 20. This is
      after the sentence with the Swet in our example.

void disease_funs(int counter)
{
     if (counter > 1)  
     {
        apply(call,tp,"hit_player",20);
        apply(call,tp,"show_hp",2);
     }
}
                                                               */
    
string id;         /* the identifier of the disease */
string elook;      /* the extra look a player has when diseased */ 
string art;        /* the kind of disease (example: "flu") */
string *mmess;     /* the messages the living gets */ 
string *omess;     /* the message the others in the room get */
string dmess;      /* the message when the object will be destructed */
string bmess;      /* the message when the player gets infected */
string file_name;  /* the filename when the disease is cloned again */
int mtime;         /* the time intervalls when the messages are called */
int dtime;         /* how long does the disease last ? */
int cia;           /* change to infect other player */
int imm;           /* when you get your disease, how immune do you get */
int delay;

int counter;   /* just a counter variable */ 
object tp;     /* the this player */
closure call;

void reset(int flag)
{
     if (flag==0)
     {
         call = #'call_other;
         id = "whisky_flu";
         elook = "is sweting and has red cheeks";
         art = "flu";
         dmess = "You feel better";
         bmess = "You caught a flu";
         mmess = 
               ({"You shiver unconfortably",
                 "You feel really hot",
                 "Swet is driping down your skin",
                  "You breath hard"});
         omess = 
               ({"shivers unconfortably",
                 "cheeks are burning",
                 "is sweating",
                 "breathes hard"});
         mtime = 20;
         delay = 4;
         imm = 8;
         cia = 50;
         file_name = "/players/whisky/obj/disease";
         counter = 0; 
       }
}

void init()
{
   object mob, *all;
   int i, sz;

     if (this_player() && environment()==this_player())
     {
         tp = this_player();
// the player is already resistance
         if ( apply(call,tp,"query_property","resist_"+art)>=random(100) ||
              apply(call,tp,"query_ghost") || !living(tp))
         {
            destruct(this_object());
            return;
         }
         all = all_inventory(this_player());

         for(sz = sizeof(all), i = 0; i < sz; i++)
         {
             if (all[i]->id("disease") && all[i]!=this_object())
             {
                 destruct(this_object());
                 return;
              }
         }
         write(bmess+"\n");
         call_out("start_effects",mtime);
     }
}

int get()
{
    return 1;
}

int drop()
{
    if (apply(call,this_player(),"query_ghost"))
    {
        return 0;
    }
    else 
      return 1;
}

void disease_funs(int counter)
{
     if (counter > 1)  /* when the player gets: You breathe hard */
     {
        apply(call,tp,"hit_player",20);
        apply(call,tp,"show_hp",2);
     }
}

string extra_look()
{
     return capitalize(apply(call,tp,"query_pronoun"))+" "+elook;
}

void init_arg(string str)
{
     counter = to_int(str);
}

string query_auto_load()
{
     return file_name+":"+counter;
}

void start_effects()   
{
   object *all;
   int i, sz, prop;

     if (!tp || !environment() || (!environment()->query_player() &&
         !environment()->query_npc()))
      {
          destruct(this_object());
          return;
      }
      if (!delay)
      {
          write(dmess+"\n");
          prop = apply(call,tp,"query_property","resist_"+art);
          if (prop < 0)
              prop = 1 + imm;
          else
              prop = prop + imm; 
          apply(call,tp,"add_property","resist_"+art,prop);
          destruct(this_object());
          return;
      }

      if ( (sizeof(mmess)-1) < counter)
          counter = 0;
      if (mmess[counter])
          write(mmess[counter]+"\n");
      if (omess[counter])
          say(apply(call,tp,"query_name")+" "+omess[counter]+"\n",tp);
      disease_funs(counter);
      delay--;
      counter++;

      if (cia > random(100))
      {
         all = filter_objects(all_inventory(environment(tp)),"query_player");
         for(sz = sizeof(all),i = 0;i < sz; i++)
         {
            if (apply(call,all[i],"query_level") < 30 &&
                !apply(call,all[i],"query_ghost") &&
                apply(call,all[i],"query_property","resist_"+art) < random(100)
                && apply(call,all[i],"query_property","resist_disease") < 
                random(100))
            {
                move_object(clone_object(file_name),all[i]);
            }
          }
       }
      call_out("start_effects",mtime);
}
      

// the id of the object to ask with if (present.....
void set_id(string arg)
{
       id = arg;
}

// that what you see when you look at the player
void set_elook(string arg)
{
       elook = arg;
}

// the art of disease : example flu
void set_art(string arg)
{
        art = arg;
}

// the messages the player gets 
void set_mmess(string *arr)
{
       mmess = arr;
}

// the messages the environment gets 
void set_omess(string *arr)
{
       omess = arr;
}

void set_file(string f)
{
     file_name = f;
}


void set_dmess(string m)
{
     dmess = m;
}

void set_bmess(string m)
{
     bmess = m;
}

void set_mtime(int arg)
{
       mtime = arg;
}

void set_delay(int arg)
{
       delay = arg;
}

void set_cia(int arg)
{
      cia = arg;
}

void set_imm(int arg)
{
      imm = arg;
}

int query_disease()
{
      return 1;
}

string query_art()
{
     return art;
}

string query_id()
{
    return id;
}

int id(string arg)
{
    return (arg == query_id() || arg == "disease");
}

