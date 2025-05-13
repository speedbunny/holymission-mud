/* the highest vikinggod himself */
inherit "obj/monster";
object boar;
int i,j;

void reset(int arg) {
   ::reset(arg);
   i=0;

   if(!arg) {
   set_name("loki");
   set_short("Loki, trickster and lover of intrigue");
   set_long("Loki, the chaotic viking god of intrigue. \n"
          + "Mighty in games and mighty in fights. \n"
          + "He is nice but cunning, so beware, O Daring One. \n");
   set_level(20);
   set_al(-500);
   set_race("deity");
   set_gender(1);
   }
}

void irritated(int i) {
string name,act;
object man,ale,odin;
   if(i==0) {
      write("Loki notices you and smiles cunningly. \n");
      environment(this_object())->set_busy(0);
      return;
      }
   if(i==1) {
      write("Loki blows in your direction. You're in the centre of a hurricane. \n");
      environment(this_object())->set_busy(0);
      return;
      }
   if(i==2) {
      write("Loki grabs you by the neck and drops you into a mug of bad ale. \n"
          + "Loki says: Now let's see if this mortal can swim. \n");
      this_player()->move_player("X#players/uglymouth/vikings/mug");
      this_player()->set_smell(capitalize(this_player()->query_pronoun()) + " smells terribly of bad ale. \n");
      return;
      }
   if(i==3) {
      write("Loki summons Frej's boar. \n"
          + "Loki says: Can you handle this one, mortal? \n");
      boar=clone_object("/players/uglymouth/vikings/monsters/boar");
      transfer(boar,"/players/uglymouth/vikings/walhalla");
      boar->charge();
      return;
      }
   if(i==4) {
   write("Loki grins demonically. \n"
       + "Loki says: You're smart, mortal, but let's see if you're smart enough for THIS! \n"
       + "Loki snaps his fingers. \n"
       + "You are magically transferred somewhere... \n\n");
   this_player()->move_player("X#players/uglymouth/vikings/portalroom");
      environment(this_object())->set_busy(0);
      return;
      }
   if(i==5) {
      write("Loki glows red hot with anger. \n"
          + "Loki shouts: I've had it with you mortal! \n"
          + "Loki takes Mjolnir and smashes it into the table, not an inch away from you. \n");
      return;
      }
   }
