#!/usr/bin/env python3

from pytube import YouTube
import subprocess

link = input("Enter youtube link: ")
yt = YouTube(link)


def get_stream_array(choice):
	stream_array = []
	if choice == 1:
		stream_choice = yt.streams.filter(only_video=True)
		ys = yt.streams.get_audio_only()
		ys.download(filename='._audio')
	elif choice == 2:
		stream_choice =  yt.streams.filter(only_audio=True)

	for stream in stream_choice:
			stream_type = str(stream).split(' ')[1:4]
			if not 'webm' in stream_type[1]:
				stream_array.append(stream_type)

	return stream_array

choice = int(input('1.) Video\n2.) Audio\nEnter your choice: '))
stream_array = get_stream_array(choice)

for stream in range(0, len(stream_array)):
	print(f"{stream+1}.)", stream_array[stream][2].split('"')[1::2][0])

tag_choice = int(input('\nEnter your choice: '))
itag = stream_array[tag_choice-1][0].split('=')[-1].split('"')[1::2][0]
ys = yt.streams.get_by_itag(itag)

if choice == 1:
	ys.download(filename='._video')

	cmd = f'ffmpeg -y -i "_audio.mp4" -r 30 -i "_video.mp4" -c:a copy -c:v copy "{ys.title}.mp4"'
	subprocess.call(cmd, shell=True) 
	cmd = 'rm "_audio.mp4" && rm "_video.mp4"'
	subprocess.call(cmd, shell=True)
elif choice == 2:
	ys.download(filename='_audio')
	cmd = f'ffmpeg -i "_audio.mp4" "{ys.title}.mp3"'
	subprocess.call(cmd, shell=True)
	cmd = 'rm "_audio.mp4"'
	subprocess.call(cmd, shell=True)
