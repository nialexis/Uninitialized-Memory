# How I approached learning my topic

I chose uninitialized memory in C from the Buffer Overflows and Memory Vulnerabilities topic. I started by asking "I am trying to understand Buffer Overflows and Memory Vulnerabilities: uninitialized memory. can you help me understand it more. I am using C to code. Does this work with both allocated and nonallocated memory?"

I started noting down how unitialized variables can interfere with other functions that might overlap. My understanding came in different stages. First I was trying to understand the basic idea that function stack's frame isn't erased when a funcion returns.

## What prompts did I use?

Can you check my understand? Stack leaks occur when function 1 returns and pops off the stack. function 2 takes function 1's old place and is able to access/see the data that was left behind from function 1. If function 2 didn't initialize their data, some of the data from function 1 can interact with function 2 and cause undefined behavior?

How would a programmer avoid security leaks like this?

## How did I engage with AI?

I asked AI to help me with some of the examples, so that way I was clearly understanding the topic. I wanted to make sure that I got more that one example, so I could explain the topic to classmates. I asked real-life questions like "How would this harm a company that I am working at as a software engineer/ can you use this in a real life scenario?"

## What I would do differently

- I'd ask for sources and check them, instead of testing things by running the code.

- I would ask for sample answers sooner, instead of just looking at the code but not understanding the different outputs. 

- I'd try explaining the concept in my own words earlier intead of asking about the real-life complications first.

## Conversation 

https://claude.ai/share/1c26b510-55a7-41b6-a9fe-ddbb0da5b68a



