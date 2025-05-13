/* This is a much simplified version of the original idea to save cpu usage */
// Portil 300894
mapping tracks,exitconvert;

reset(int flag) {
        tracks=([]);
        if(!flag) exitconvert=(["n":"north","ne":"northeast","e":"east","se":"southeast","s":"south","sw":"southwest","w":"west","nw":"northwest","d":"down","u":"up"]);
        return;
}

add_new_track(string str) {
        mapping people;
        string *exits;
        object env,tp;
        tp=this_player();
        env=environment(tp);
        if(member_array(str,env->query_room("dest_dir"))==-1) {
		if(exitconvert[str]) return add_new_track(exitconvert[str]);
		notify_fail("That direction doesn`t seem to be an obvious exit.\n");
		return 0;
        }
        if(people=tracks[env]) {
        exits=people[tp->query_real_name()];
        if(exits) { 
          if(member_array(str,exits)!=-1) {
            write("You have already placed a track pointing towards that exit.\n");
            return 1;
        } else {
            exits+=({str});
            if(sizeof(exits)==3) exits[0]=str+" and "+exits[0]; 
             else
                exits[0]=str+", "+exits[0];
        }} else
            exits=({str,str});
        
          people=m_delete(people,tp->query_real_name());
          people+=([tp->query_real_name():exits]);
        } else
          people=([tp->query_real_name():({str,str})]);
        tracks=m_delete(tracks,env);
        tracks+=([env:people]);
        write("You make a mark on the floor.\n");
        say(tp->query_name()+" appears to make a mark on the floor.\n");
	env->move(str);
        return 1;
}

query_tracks() {
        mapping people;
        string *exits,*who,text;
        int i,sizei,sizeexits;
        if(!people=tracks[environment(this_player())]) {
                write("There are no tracks here.\n");
                return 1;
        }
        who=m_indices(people);
        sizei=sizeof(who);
        for(i=0;i<sizei;i++) {
          exits=people[who[i]];
            sizeexits=sizeof(exits)-1;
            if(this_player()->query_real_name()==who[i]) text="You have left ";
            else     text=capitalize(who[i])+" has left ";
            if(sizeexits==1) text+="a track pointing towards the "+exits[0]+" exit.\n";
              else text+="tracks pointing towards the "+exits[0]+" exits.\n";
            write(text);
        }
        return 1;
}
