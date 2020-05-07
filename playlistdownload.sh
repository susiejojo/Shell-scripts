#!/bin/bash

#installing youtube-dl
sudo wget https://yt-dl.org/latest/youtube-dl -O /usr/local/bin/youtube-dl
sudo chmod a+x /usr/local/bin/youtube-dl
hash -r

#downloading playlist
youtube-dl -cit --extract-audio --audio-format mp3 $1

