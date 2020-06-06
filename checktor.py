#!/usr/bin/env python3

import requests

r = requests.get("https://check.torproject.org/").text
start = r.find("<title>")
end = r.find("</title>")

out = r[start:end].split(">")[1]

print(out)
