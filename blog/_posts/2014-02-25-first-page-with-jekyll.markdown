---
layout: post
title:  "My first post with jekyll"
date:   2014-02-25 18:35:17
categories: posts
---

# Test most common markdown synax effects in the jekyll

header
==================================

## h2 header
## h3 header
### h4 header


Emphasis
=================
*italics*
**bold**
**_bold_ and italics**
~~cross line~~

list
==================

1. first
2. second
 ..*second sub
3. third
 ..1.third_1
 ..2.third_2
4. fouth
 ...fouth content1
 ...blabla
 ...end

links
=======================

[link to google](http://www.google.com "google site")
also can use the link define below [google-url]

[google-url]: http://www.google.com



code highlight
==========================

{% highlight c linenos %}
#include <stdio.h>

int main(){
	// comment 
	printf("hello world \n");
	return 0;
}

{% endhighlight %}

image
============================

![girl picture]({{site.url}}/images/girl.jpg "beauty, isn't it?")


Blockquotes
===========================

> block message content
> can also add *italics* and **bold**

gist
=============================

{% gist 6681385 %}

