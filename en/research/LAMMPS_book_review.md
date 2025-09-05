---
layout: post_en
title: "Book review: Extending and Modifying LAMMPS"
date: March 3rd, 2021
author: Eugen
category: research
tags: [simulations, LAMMPS]
menu:
  MD/MC simulations (LAMMPS):
    link: [/en/research/simulations, onsite]
  Political science:
    link: [/en/research/politics, onsite]
---
## An introduction: The pitfalls of research programming or <br/> Why you should use LAMMPS

I strongly believe that properly engineered, documented and maintained open-source software should be used in scientific research whenever possible, especially if it is already established and time-proven in a large community. I probably have a very strong opinion on this because of my formal education and background in software engineering, that is to say I've seen a lot of bad programming and I know what the consequences can be and often are. In any case, this is why I am a big supporter of LAMMPS and encourage anyone who has a need to perform MD or any other kind of simulations to look into LAMMPS before starting to write any code of their own or using some "home-made", in-group developed "software".

Unfortunately, because of the nature of research as such, two problems or situations typically arise:

1) These software suites (like LAMMPS) need to be as general as possible in order to accommodate a wide range of possible applications. Because of that they are often quite abstract in their structure and grow big and complex with many options and possibilities. This makes them have **a steep learning curve** which is always off-putting and especially so for young researchers just starting a project, because at that time it usually seems to them their needs are very limited and simple (and there are a million other things they have to do and would rather spend their limited time on). However, this kind of thinking is usually a trap because research is of such a nature that one cannot tell where it will lead and almost certainly very soon one will find themselves in need of more and more things that they will need to program and implement for themselves, things usually well beyond their knowledge and expertise to do properly. This is usually both hugely time-consuming and frustrating ([as if early research positions aren't psychologically challenging enough](https://www.nature.com/articles/d41586-019-03489-1)), and if managed to be done at all almost certainly results in bad software and suboptimal science that in the worst-case scenario (which is, in my opinion, not so rare) generates faulty results that become published and remain unnoticed.

2) Even if one does not fall into this trap and opts to use and spend some extra time initially to master a more general and established software suite like LAMMPS, the specificity of research often leads one to **a need for features that the software**, regardless of the number of users and length of existence, **does not (yet) have**. However, if the software is properly designed, documented and maintained, and open-source, as LAMMPS is, then one can relatively easily adapt it and expand it to their needs, especially if one is already familiar with it as a "regular" user. This extra time and effort, of learning how to modify and add to a software suite like LAMMPS, quickly pays off because one then has to write only a small fraction of the code one would otherwise have to and even that relying heavily on existing code as templates. This minimises the chance for bugs and faulty code and in any case minimises the amount of code where those bugs could be and thus the time needed to find them and correct them. On top of that, this newly developed code can then be added to the software for everybody else to use which makes it easier for others in the field to check your code and so increases the likelihood of eventual bugs being found and corrected, which contributes to more solid science being done. This also enables other researchers to use your code and not waste time on programming, which makes science as a whole a more efficient endeavour and also generates a huge sense of contribution for the one who wrote the code (maybe being a little cynical here, but often this will be or feel like a more useful contribution to science than the science being done).

All that being said it still is quite hard, confusing and time-consuming to get around and figure out such a huge amount of code, files and structure just from the code and raw documentation itself (this is how I have done it, so I would know, and I'm no beginner in programming). This is especially true for beginners in programming, which young researchers overwhelmingly are, and that is exactly who and what this book is ideally written for and it is, in my opinion, very close to being perfect for the job.

### Me as the reader (a reference point)

I started using LAMMPS as soon as I started my PhD in biophysics which was to be about investigating the mechanism of amyloid formation using multiscale MD/MC simulations of coarse-grained models. I spent a lot of time at the start getting to know LAMMPS through both simple uses and reading the documentation and very soon I needed things that weren't already there (or circumvent them in inefficient and ugly ways). This led to me becoming a small contributor to LAMMPS on GitHub, the stuff I wrote (a pair potential, a wall potential and some other tweaks and bug corrections) being included in the stable releases, which led to me being kindly asked by the publishers of this book to write a review of it.

I like to read slowly and think a lot, so I like books that are as short as possible and get to the point quickly, that contain only what is relevant and interesting, that talk to the reader on the level appropriate for their education and previous expected knowledge and expect them to think, not do the thinking for them. This is especially true for books on programming, since programming has to be a hands-on learning experience and there is the whole internet to help you with it (tutorials, documentation, exchange of experience by sites like Stack Overflow, GitHub etc.).

One last piece of possibly relevant information: I read this book on my laptop as a PDF file and had no visual or technical problems with it (except maybe with the code snippets, I touch on that at end of next section).

## The book
<img src="/imgs/LAMMPS book cover.png" style="float:right; width:40%; padding:5px 0px 5px 20px">

*Extending and Modifying LAMMPS* is a technical book that assumes you, the reader, have used LAMMPS in at least some basic capacity and that you have a grasp of and some experience with the C programming language, but beyond that it takes you by the hand, so to speak, and leads you gently, step by step through the logic and structure of LAMMPS. It shows to you exactly what you need to most quickly understand how LAMMPS works and start adding to it and modifying it in useful ways, while abstracting away and ignoring irrelevant details that you will figure out yourself if and when you'll need to. I think it does a great job of showing you (only) the important things and balancing textual explanations with code examples, which is why the book is not bulky and reads easily.

A very neat and useful feature of the book are the review questions at the end of each chapter that allow you to think about what you have just read and check if you actually understood, let it settle a bit before going further on. I like that there are only a few of them, so the book doesn't treat you like a student (to put it mildly), and that the answers to all of them are located at the end of the book. This allows you to both not be distracted by the answer while thinking about the question (as you would be if they were immediately below) and to easily check if you're correct in your thinking once you have thought it through.

The book uses and assumes use of only the most basic tools everybody probably is or can easily become familiar with and its beginner-friendly character is especially evident by its appendices which are, in my opinion, the book's little gems and nuggets.

The first appendix is basically a tutorial for building LAMMPS from source-code on both Windows and Linux platforms with common, standard tools like cmake, and the second one is a short motivational introduction to proper debugging showing how to do it with various common tools. The second appendix ends rather oddly with a very useful but seemingly bizarrely misplaced section named "Insight into sbmask()".

The third appendix features a very brief but extremely useful introduction to what MPI is, how it works and how it is usually used in LAMMPS. That is, in my opinion, a great asset of the book since MPI is very important for LAMMPS but also conceptually very different from "normal" programming and complex in its entirety.

The last appendix is about the differences between two stable LAMMPS versions: *3Mar20* which the book is based on and *29Oct20* which featured some significant conceptual, non-cosmetic changes. Although it would be ideal if the book was based on the newer version, the existence of this appendix would still be useful, for example to people who have dealt with earlier versions of LAMMPS to quickly get up to speed (like me, and a big thank you to the authors for this) or maybe to those that have some old LAMMPS code (of their own or somebody else's) that they want to incorporate into the newest LAMMPS version.

Perhaps the best reference that I can give for this book is that while I was reading it to write a review (well, skimming through it really, if we're being honest, but that makes the point even stronger if you think about it) I learned a few very useful things for my work that would have otherwise taken me a lot more time to figure out myself.

The only objection, or perhaps more of a suggestion, I have about the contents of the book is that it is focused solely on MD and doesn't even mention LAMMPS' ability to perform MC simulations. I think the book would be even better, more complete and generally more useful if the MC package was mentioned and some examples done with code from that package (e.g. the gcmc fix). This is because I believe LAMMPS to be ideally suited for hybrid MD-MC simulations for which it is most likely one will have to add code of their own since the MC package is very minimal (since LAMMPS really was made for MD) and those kinds of simulations are usually very specific and unique. However, this observation might be based a bit too much on personal experiences and wishes.

Lastly, it is a shame and perhaps a bit ugly to look at (especially when zooming in), that the code snippets are screenshots, so they are neither searchable nor can one copy the code from the book. But this is not that big of a problem since all the code is available in the LAMMPS source code and on [the GitHub page of the book](https://github.com/PacktPublishing/Extending-and-Modifying-LAMMPS-Writing-Your-Own-Source-Code).

## Final verdict

If you are doing research that requires (MD) simulations I strongly recommend that you use LAMMPS, and if you are using LAMMPS reading this book will probably result in a better understanding and more efficient use of it. But if (when) you will need something very specific for your research, something that is not yet implemented in LAMMPS (or you have to go a very roundabout and inefficient way of doing it) - get your hands on this book, it will save you a lot of time.

I truly believe that this book fills a hole in the LAMMPS/simulation community and I can only say that I wish it existed 3 years ago when I was doing it for the first time. I honestly think that every group that uses LAMMPS in their research would be smart to have a copy of this book around.
