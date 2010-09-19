<?xml version="1.0"?>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<meta content="Loggerhead/1.17 Python/2.6.5 Bazaar/2.2.0 Paste/1.7.2 PasteDeploy/1.3.3 SimpleTAL/4.1 Pygments/1.2.2 simplejson/2.0.9" name="generator" />
<title>~benlau/penpen/trunk : contents of src/libpenpen/ppxmlpaper.h at revision 78</title>
<link href="/static/css/global.css" rel="stylesheet" />

<script type="text/javascript">
var global_path = 'http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/';
var collapsed_icon_path = '/static/images/treeCollapsed.png';
var expanded_icon_path = '/static/images/treeExpanded.png';
</script>
<script src="/static/javascript/yui/build/yui/yui-min.js" type="text/javascript"></script>
<script src="/static/javascript/yui/build/oop/oop-min.js" type="text/javascript"></script>
<script src="/static/javascript/yui/build/event/event-min.js" type="text/javascript"></script>
<script src="/static/javascript/yui/build/attribute/attribute-min.js" type="text/javascript"></script>
<script src="/static/javascript/yui/build/base/base-min.js" type="text/javascript"></script>
<script src="/static/javascript/yui/build/dom/dom-min.js" type="text/javascript"></script>
<script src="/static/javascript/yui/build/node/node-min.js" type="text/javascript"></script>
<script src="/static/javascript/yui/build/anim/anim-min.js" type="text/javascript"></script>
<script src="/static/javascript/yui/build/io/io-base-min.js" type="text/javascript"></script>
<script src="/static/javascript/custom.js" type="text/javascript"></script>

<link href="/static/css/annotate.css" media="all" type="text/css" rel="stylesheet" />
<link href="/static/css/highlight.css" media="all" type="text/css" rel="stylesheet" />

</head>
<body>


<ul id="menuTabs">


<li><a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/changes" title="Changes">Changes</a></li>
<li><a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files" title="Files" id="on">Files</a></li>
<li><a href="https://help.launchpad.net/Loggerhead" title="Help">Help</a></li>

</ul>

<div id="loggerheadCont">
<div id="search_terms"></div>
<h1>

<a href="https://code.launchpad.net/~benlau/penpen/trunk">~benlau/penpen/trunk</a>


<span>: <span class="breadcrumb">
/<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78?file_id=src-20100614163637-a9u616hzyeh125l5-1">src</a>/<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78?file_id=libpenpen-20100725033312-lcpnhscm51x8wpur-1">libpenpen</a>/ppxmlpaper.h
</span> (revision 78)</span>
</h1>
<div>

<ul id="submenuTabs">
<li id="first">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78">browse files</a>
</li>
<li>
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/78">view revision</a>
</li>
<li>
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/changes?filter_file_id=paperxml.h-20100725053745-lcvu7lqjusw0tvfc-2">view changes to this file</a>
</li>
<li id="last">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/download/head%3A/paperxml.h-20100725053745-lcvu7lqjusw0tvfc-2/ppxmlpaper.h">download file</a>
</li>
</ul>
<div class="annotate">
<table id="logentries">
<tr class="logheader">
<td class="annoLineTit">Line</td>
<td class="annoRevTit">Revision</td>
<td class="annoContTit">Contents</td>
</tr>
<tr class="blueRow1">
<td class="annoLine"><a id="L1" href="#L1">1</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre><span class="pyg-cm">/**</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L2" href="#L2">2</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm"> * @author Ben Lau &lt;xbenlau@gmail.com&gt;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L3" href="#L3">3</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm"> */</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L4" href="#L4">4</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L5" href="#L5">5</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/63" title="63 by Ben Lau, on 31 Jul 2010 13:41 (2010-07-31 13:41:58)">63</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#ifndef PPXMLPAPER_H</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L6" href="#L6">6</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#define PPXMLPAPER_H</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L7" href="#L7">7</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L8" href="#L8">8</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/43" title="43 by Ben Lau, on 25 Jul 2010 09:21 (2010-07-25 09:21:33)">43</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QDomDocument&gt;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L9" href="#L9">9</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &quot;ppgraphicsstroke.h&quot;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L10" href="#L10">10</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/65" title="65 by Ben Lau, on 03 Aug 2010 13:03 (2010-08-03 13:03:45)">65</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &quot;ppbackground.h&quot;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L11" href="#L11">11</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &quot;pppaper.h&quot;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L12" href="#L12">12</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/44" title="44 by Ben Lau, on 25 Jul 2010 10:28 (2010-07-25 10:28:02)">44</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L13" href="#L13">13</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/59" title="59 by Ben Lau, on 31 Jul 2010 05:55 (2010-07-31 05:55:50)">59</a>
</td>
<td class="annoCont"><pre><span class="pyg-c1">/// XML representation of handwriting data</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L14" href="#L14">14</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L15" href="#L15">15</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/52" title="52 by Ben Lau, on 28 Jul 2010 04:04 (2010-07-28 04:04:51)">52</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">class</span><span class="pyg-"> </span><span class="pyg-n">PPXmlPaper</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L16" href="#L16">16</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L17" href="#L17">17</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-nl">public:</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L18" href="#L18">18</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/52" title="52 by Ben Lau, on 28 Jul 2010 04:04 (2010-07-28 04:04:51)">52</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">PPXmlPaper</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L19" href="#L19">19</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L20" href="#L20">20</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-c1">/// Read from paper, generate a new XML representation</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L21" href="#L21">21</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/60" title="60 by Ben Lau, on 31 Jul 2010 06:19 (2010-07-31 06:19:32)">60</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">virtual</span><span class="pyg-"> </span><span class="pyg-n">QDomElement</span><span class="pyg-"> </span><span class="pyg-n">read</span><span class="pyg-p">(</span><span class="pyg-n">PPPaper</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">paper</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L22" href="#L22">22</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L23" href="#L23">23</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-c1">/// Read from element</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L24" href="#L24">24</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/63" title="63 by Ben Lau, on 31 Jul 2010 13:41 (2010-07-31 13:41:58)">63</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">read</span><span class="pyg-p">(</span><span class="pyg-n">QDomElement</span><span class="pyg-"> </span><span class="pyg-n">elem</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L25" href="#L25">25</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L26" href="#L26">26</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-c1">/// Write the XML representation to a paper instance</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L27" href="#L27">27</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/63" title="63 by Ben Lau, on 31 Jul 2010 13:41 (2010-07-31 13:41:58)">63</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">bool</span><span class="pyg-"> </span><span class="pyg-n">write</span><span class="pyg-p">(</span><span class="pyg-n">PPPaper</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">paper</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L28" href="#L28">28</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L29" href="#L29">29</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-c1">/// Write the XML represent to be the child of a QDomNode</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L30" href="#L30">30</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/63" title="63 by Ben Lau, on 31 Jul 2010 13:41 (2010-07-31 13:41:58)">63</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">bool</span><span class="pyg-"> </span><span class="pyg-n">write</span><span class="pyg-p">(</span><span class="pyg-n">QDomNode</span><span class="pyg-"> </span><span class="pyg-n">node</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L31" href="#L31">31</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L32" href="#L32">32</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">setDocument</span><span class="pyg-p">(</span><span class="pyg-n">QDomDocument</span><span class="pyg-"> </span><span class="pyg-o">&amp;</span><span class="pyg-n">val</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L33" href="#L33">33</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QDomDocument</span><span class="pyg-"> </span><span class="pyg-n">document</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L34" href="#L34">34</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L35" href="#L35">35</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/63" title="63 by Ben Lau, on 31 Jul 2010 13:41 (2010-07-31 13:41:58)">63</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QDomElement</span><span class="pyg-"> </span><span class="pyg-n">createStrokeElement</span><span class="pyg-p">(</span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">stroke</span><span class="pyg-"> </span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-n">QDomDocument</span><span class="pyg-"> </span><span class="pyg-o">&amp;</span><span class="pyg-n">doc</span><span class="pyg-"> </span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L36" href="#L36">36</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">bool</span><span class="pyg-"> </span><span class="pyg-n">setStrokeFromElement</span><span class="pyg-p">(</span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">stroke</span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-n">QDomElement</span><span class="pyg-"> </span><span class="pyg-o">&amp;</span><span class="pyg-n">element</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L37" href="#L37">37</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/41" title="41 by Ben Lau, on 25 Jul 2010 06:23 (2010-07-25 06:23:01)">41</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L38" href="#L38">38</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-nl">private:</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L39" href="#L39">39</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QDomDocument</span><span class="pyg-"> </span><span class="pyg-n">m_document</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L40" href="#L40">40</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L41" href="#L41">41</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">};</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L42" href="#L42">42</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L43" href="#L43">43</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/63" title="63 by Ben Lau, on 31 Jul 2010 13:41 (2010-07-31 13:41:58)">63</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#endif </span><span class="pyg-c1">// PPXMLPAPER_H</span></pre></td>
</tr>
</table>
</div>
</div>
<p class="fl">Loggerhead 1.17 is a web-based interface for <a href="http://bazaar-vcs.org/">Bazaar</a> branches</p>
</div>
</body>
</html>