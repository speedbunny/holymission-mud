int level,age,is_wizard,experience;
string last_login_time;
static int i,j,above_value,total_players,size;
static mixed *player;
static string *players_dir,timenow,timeago,year1,year2,*indiv_dir,check;

get_list() {
	string junk,timea,timeb;
	player=({});
	players_dir=get_dir("/p/.");
	i=0; j=0; above_value=0; indiv_dir=0;
	timea=ctime(time());
	timeb=ctime(time()-2332800);
	sscanf(timea,"%s %s %s %s %s",junk,timenow,check,junk,year1);
	if(check=="")
                sscanf(timea,"%s %s  %s %s %s",junk,timenow,junk,junk,year1);
	sscanf(timeb,"%s %s %s %s %s",junk,timeago,check,junk,year2);
	if(check=="")
		sscanf(timeb,"%s %s  %s %s %s",junk,timeago,junk,junk,year2);
	total_players=0;
        call_out("next_bit",2);
	return;
}


next_bit() {
	string file,time,junk,year;
	if(!indiv_dir) { indiv_dir=get_dir("/p/"+players_dir[i]+"/.");
			 size=sizeof(indiv_dir);
	}
	if(file_size("/banish/"+indiv_dir[j])==-1 &&
		      sscanf(indiv_dir[j],"%s.o",file)) {
	      age=0;level=0;experience=0;
	      if(restore_object("p/"+players_dir[i]+"/"+file)) {
		total_players++;
		if(age>above_value) {
		restore_object("/players/moonchild/misc/fingerdata/"+file);
sscanf(last_login_time,"%s %s %s %s %s",junk,time,check,junk,year);
		if(check=="")
		  sscanf(last_login_time,"%s %s  %s %s %s",junk,time,junk,junk,year);
		if((time==timenow && year1==year) || (time==timeago && year2==year))
		  player+=({ ({ file,level,age,experience }) });
		}
	      }
	}
	j++;
	if(j>=size) { indiv_dir=0; j=0; i++; }
	if(sizeof(player)>30 && !indiv_dir) {	
	  player=sort_array(player,"sort_age",this_object());
	  above_value=player[30][2];
	  player=filter_array(player,"filter",this_object(),above_value);
	}
	if(i<sizeof(players_dir)) call_out("next_bit",2);
	else call_out("showit",2);
	return;
}

showit() {
	write("List completed with "+total_players+" players scanned.\n");
	rm("/players/portil/funobj/list");
	for(i=0;i<30;i++) 
		write_file("/players/portil/funobj/list","Position "+(i+1)+": "+capitalize(player[i][0])+"\n  Level "+player[i][1]+", and has played for "+find_age(player[i][2])+".\n");
}

sort_age(mixed x,mixed y) { return x[2]<y[2]; }

filter(mixed x,int test) { if(x[2]>test) return 1; else return 0; }

find_age(int num) {
	string amount;
	amount=num/43200+" days and ";
	num-=(num/43200)*43200;
	amount+=num/1800+" hours";
	return amount;
}

list_so_far() {
	int l,length;
	string str,name;
	if(!length=sizeof(player)) {
		write("No list.\n");
		return;
	}
	if(length>30) length=30;
	str="Percentage completed: "+((100*i)/sizeof(players_dir))+"%\n";
	if(indiv_dir && sscanf(indiv_dir[j],"%s.o",name)) str+="Scanning the player file for "+capitalize(name)+".\n";
	str+="List with "+total_players+" players scanned so far.\n";
	for(l=0;l<length;l++) 
		str+="Position "+(l+1)+": "+capitalize(player[l][0])+"\n  Level "+player[l][1]+", and has played for "+find_age(player[l][2])+"\n";
	write(str);
}
