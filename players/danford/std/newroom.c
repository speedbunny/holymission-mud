inherit "room/room";

varargs int add_exit(string direction, mixed dest) {
    if(!dest_dir)
	dest_dir = ([ ]);
	
    if(dest_dir[direction])
	return 0;
    
    dest_dir[direction] = ({ dest });
    return 1;
}

int remove_exit(string direction) {
    if(!dest_dir)
	dest_dir = ([ ]);
	
    if(dest_dir[direction])
	return 0;
    map_delete(dest_dir,diretion);
    return 1;
}
