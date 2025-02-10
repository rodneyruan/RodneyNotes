```
!curl https://ollama.ai/install.sh | sh

!echo 'debconf debconf/frontend select Noninteractive' | sudo debconf-set-selections
!sudo apt-get update && sudo apt-get install -y cuda-drivers

import os

# Set LD_LIBRARY_PATH so the system NVIDIA library
os.environ.update({'LD_LIBRARY_PATH': '/usr/lib64-nvidia'})
```
```
!nohup ollama serve &
```
```
!ollama pull deepseek-r1:32b
```
```
!pip install ollama
```
```
import ollama
response = ollama.chat(model='deepseek-r1:32b', messages=[
  {
    'role': 'user',
    'content': "How many r's are in a strawberry?",
  },
])
print(response['message']['content'])
```
