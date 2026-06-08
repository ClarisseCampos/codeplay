from pytubefix import YouTube

#video metadata

url = input("Youtube URL: ")

# Initialize the YouTube object
yt = YouTube(url)

# Print core metadata
print(f"Title: {yt.title}")
print(f"Views: {yt.views}")
print(f"Author: {yt.author}")
print(f"Thumbnail URL: {yt.thumbnail_url}")
