/*
 * playlistplayer.cpp
 *
 *  Created on: 30 Dec 2015
 *      Author: sjh
 */


#include "playlistplayer.h"

playlist_player::playlist_player() {


    set_title( "seq24 - Playlizt Editor");
    set_size_request(700, 400);

}

playlist_player::~playlist_player() {
	// TODO Auto-generated destructor stub
}


void
playlist_player::init_before_show()
{
	// TODO this was copied from perfedit.cpp
    //m_perfroll->init_before_show();
    //m_perftime->init_before_show();

	//TODO: probably a good idea to check the playlist file at this point??
}
