<?xml version="1.0"?>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<meta content="Loggerhead/1.17 Python/2.6.5 Bazaar/2.2.0 Paste/1.7.2 PasteDeploy/1.3.3 SimpleTAL/4.1 Pygments/1.2.2 simplejson/2.0.9" name="generator" />
<title>~benlau/penpen/trunk : contents of src/libpenpen/pppaperwidget.cpp at revision 78</title>
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
/<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78?file_id=src-20100614163637-a9u616hzyeh125l5-1">src</a>/<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78?file_id=libpenpen-20100725033312-lcpnhscm51x8wpur-1">libpenpen</a>/pppaperwidget.cpp
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
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/changes?filter_file_id=pppaperwidget.cpp-20100729163107-y0uzjptzprz249go-1">view changes to this file</a>
</li>
<li id="last">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/download/head%3A/pppaperwidget.cpp-20100729163107-y0uzjptzprz249go-1/pppaperwidget.cpp">download file</a>
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
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/56" title="56 by Ben Lau, on 29 Jul 2010 17:03 (2010-07-29 17:03:56)">56</a>
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
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L5" href="#L5">5</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QtCore&gt;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L6" href="#L6">6</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QResizeEvent&gt;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L7" href="#L7">7</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &quot;pppaperwidget.h&quot;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L8" href="#L8">8</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/57" title="57 by Ben Lau, on 29 Jul 2010 17:25 (2010-07-29 17:25:24)">57</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &quot;ppxmlpaper.h&quot;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L9" href="#L9">9</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/56" title="56 by Ben Lau, on 29 Jul 2010 17:03 (2010-07-29 17:03:56)">56</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L10" href="#L10">10</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-n">PPPaperWidget</span><span class="pyg-o">::</span><span class="pyg-n">PPPaperWidget</span><span class="pyg-p">(</span><span class="pyg-n">QWidget</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">parent</span><span class="pyg-p">)</span><span class="pyg-"> </span><span class="pyg-o">:</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L11" href="#L11">11</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QGraphicsView</span><span class="pyg-p">(</span><span class="pyg-n">parent</span><span class="pyg-p">)</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L12" href="#L12">12</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L13" href="#L13">13</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">setVerticalScrollBarPolicy</span><span class="pyg-p">(</span><span class="pyg-n">Qt</span><span class="pyg-o">::</span><span class="pyg-n">ScrollBarAlwaysOff</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L14" href="#L14">14</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">setHorizontalScrollBarPolicy</span><span class="pyg-p">(</span><span class="pyg-n">Qt</span><span class="pyg-o">::</span><span class="pyg-n">ScrollBarAlwaysOff</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L15" href="#L15">15</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L16" href="#L16">16</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QGraphicsScene</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">scene</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-k">new</span><span class="pyg-"> </span><span class="pyg-n">QGraphicsScene</span><span class="pyg-p">(</span><span class="pyg-k">this</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L17" href="#L17">17</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">setScene</span><span class="pyg-p">(</span><span class="pyg-n">scene</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L18" href="#L18">18</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L19" href="#L19">19</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_pencilBox</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-k">new</span><span class="pyg-"> </span><span class="pyg-n">PPPencilBox</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L20" href="#L20">20</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">scene</span><span class="pyg-o">-&gt;</span><span class="pyg-n">addItem</span><span class="pyg-p">(</span><span class="pyg-n">m_pencilBox</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L21" href="#L21">21</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L22" href="#L22">22</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_paper</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-k">new</span><span class="pyg-"> </span><span class="pyg-n">PPPaper</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L23" href="#L23">23</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">scene</span><span class="pyg-o">-&gt;</span><span class="pyg-n">addItem</span><span class="pyg-p">(</span><span class="pyg-n">m_paper</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L24" href="#L24">24</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L25" href="#L25">25</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_paper</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setFlag</span><span class="pyg-p">(</span><span class="pyg-n">QGraphicsItem</span><span class="pyg-o">::</span><span class="pyg-n">ItemClipsToShape</span><span class="pyg-p">,</span><span class="pyg-kc">true</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L26" href="#L26">26</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_paper</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setFlag</span><span class="pyg-p">(</span><span class="pyg-n">QGraphicsItem</span><span class="pyg-o">::</span><span class="pyg-n">ItemClipsChildrenToShape</span><span class="pyg-p">,</span><span class="pyg-kc">true</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L27" href="#L27">27</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L28" href="#L28">28</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_paper</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setRect</span><span class="pyg-p">(</span><span class="pyg-n">QRect</span><span class="pyg-p">(</span><span class="pyg-mi">0</span><span class="pyg-p">,</span><span class="pyg-mi">0</span><span class="pyg-p">,</span><span class="pyg-mi">100</span><span class="pyg-p">,</span><span class="pyg-mi">100</span><span class="pyg-p">));</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L29" href="#L29">29</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L30" href="#L30">30</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_pencilBox</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setPaper</span><span class="pyg-p">(</span><span class="pyg-n">m_paper</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L31" href="#L31">31</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/57" title="57 by Ben Lau, on 29 Jul 2010 17:25 (2010-07-29 17:25:24)">57</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L32" href="#L32">32</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L33" href="#L33">33</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QRect</span><span class="pyg-"> </span><span class="pyg-n">rect</span><span class="pyg-p">(</span><span class="pyg-mi">0</span><span class="pyg-p">,</span><span class="pyg-mi">0</span><span class="pyg-p">,</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L34" href="#L34">34</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">               </span><span class="pyg-n">size</span><span class="pyg-p">().</span><span class="pyg-n">width</span><span class="pyg-p">(),</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L35" href="#L35">35</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">               </span><span class="pyg-n">size</span><span class="pyg-p">().</span><span class="pyg-n">height</span><span class="pyg-p">());</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L36" href="#L36">36</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L37" href="#L37">37</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">scene</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setSceneRect</span><span class="pyg-p">(</span><span class="pyg-n">rect</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L38" href="#L38">38</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_paper</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setRect</span><span class="pyg-p">(</span><span class="pyg-n">rect</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L39" href="#L39">39</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/56" title="56 by Ben Lau, on 29 Jul 2010 17:03 (2010-07-29 17:03:56)">56</a>
</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L40" href="#L40">40</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L41" href="#L41">41</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">PPPaperWidget</span><span class="pyg-o">::</span><span class="pyg-n">resizeEvent</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-"> </span><span class="pyg-n">QResizeEvent</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-"> </span><span class="pyg-n">event</span><span class="pyg-"> </span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L42" href="#L42">42</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QGraphicsScene</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">s</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">scene</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L43" href="#L43">43</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QRect</span><span class="pyg-"> </span><span class="pyg-n">rect</span><span class="pyg-p">(</span><span class="pyg-mi">0</span><span class="pyg-p">,</span><span class="pyg-mi">0</span><span class="pyg-p">,</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L44" href="#L44">44</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">               </span><span class="pyg-n">event</span><span class="pyg-o">-&gt;</span><span class="pyg-n">size</span><span class="pyg-p">().</span><span class="pyg-n">width</span><span class="pyg-p">(),</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L45" href="#L45">45</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">               </span><span class="pyg-n">event</span><span class="pyg-o">-&gt;</span><span class="pyg-n">size</span><span class="pyg-p">().</span><span class="pyg-n">height</span><span class="pyg-p">());</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L46" href="#L46">46</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">s</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setSceneRect</span><span class="pyg-p">(</span><span class="pyg-n">rect</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L47" href="#L47">47</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L48" href="#L48">48</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_paper</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setRect</span><span class="pyg-p">(</span><span class="pyg-n">rect</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L49" href="#L49">49</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L50" href="#L50">50</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QGraphicsView</span><span class="pyg-o">::</span><span class="pyg-n">resizeEvent</span><span class="pyg-p">(</span><span class="pyg-n">event</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L51" href="#L51">51</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L52" href="#L52">52</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L53" href="#L53">53</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-n">PPPencilBox</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">PPPaperWidget</span><span class="pyg-o">::</span><span class="pyg-n">pencilBox</span><span class="pyg-p">(){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L54" href="#L54">54</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">m_pencilBox</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L55" href="#L55">55</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L56" href="#L56">56</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L57" href="#L57">57</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-n">PPPaper</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">PPPaperWidget</span><span class="pyg-o">::</span><span class="pyg-n">paper</span><span class="pyg-p">(){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L58" href="#L58">58</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">m_paper</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L59" href="#L59">59</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L60" href="#L60">60</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/57" title="57 by Ben Lau, on 29 Jul 2010 17:25 (2010-07-29 17:25:24)">57</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L61" href="#L61">61</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-kt">bool</span><span class="pyg-"> </span><span class="pyg-n">PPPaperWidget</span><span class="pyg-o">::</span><span class="pyg-n">setContent</span><span class="pyg-p">(</span><span class="pyg-n">QByteArray</span><span class="pyg-"> </span><span class="pyg-n">data</span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L62" href="#L62">62</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QDomDocument</span><span class="pyg-"> </span><span class="pyg-n">doc</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L63" href="#L63">63</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">if</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-n">doc</span><span class="pyg-p">.</span><span class="pyg-n">setContent</span><span class="pyg-p">(</span><span class="pyg-n">data</span><span class="pyg-p">)){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L64" href="#L64">64</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">PPXmlPaper</span><span class="pyg-"> </span><span class="pyg-n">xml</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L65" href="#L65">65</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">QDomElement</span><span class="pyg-"> </span><span class="pyg-n">paperElem</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">doc</span><span class="pyg-p">.</span><span class="pyg-n">firstChildElement</span><span class="pyg-p">(</span><span class="pyg-s">&quot;paper&quot;</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L66" href="#L66">66</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">xml</span><span class="pyg-p">.</span><span class="pyg-n">read</span><span class="pyg-p">(</span><span class="pyg-n">paperElem</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L67" href="#L67">67</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">xml</span><span class="pyg-p">.</span><span class="pyg-n">write</span><span class="pyg-p">(</span><span class="pyg-n">m_paper</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L68" href="#L68">68</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L69" href="#L69">69</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-kc">false</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L70" href="#L70">70</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L71" href="#L71">71</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L72" href="#L72">72</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-n">QByteArray</span><span class="pyg-"> </span><span class="pyg-n">PPPaperWidget</span><span class="pyg-o">::</span><span class="pyg-n">toByteArray</span><span class="pyg-p">(</span><span class="pyg-kt">int</span><span class="pyg-"> </span><span class="pyg-n">indent</span><span class="pyg-p">)</span><span class="pyg-"> </span><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L73" href="#L73">73</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QDomDocument</span><span class="pyg-"> </span><span class="pyg-n">doc</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L74" href="#L74">74</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">doc</span><span class="pyg-p">.</span><span class="pyg-n">setContent</span><span class="pyg-p">(</span><span class="pyg-n">QByteArray</span><span class="pyg-p">(</span><span class="pyg-s">&quot;&quot;</span><span class="pyg-p">));</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L75" href="#L75">75</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L76" href="#L76">76</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">PPXmlPaper</span><span class="pyg-"> </span><span class="pyg-n">xml</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L77" href="#L77">77</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L78" href="#L78">78</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QDomElement</span><span class="pyg-"> </span><span class="pyg-n">paperElem</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">xml</span><span class="pyg-p">.</span><span class="pyg-n">read</span><span class="pyg-p">(</span><span class="pyg-n">m_paper</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L79" href="#L79">79</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">doc</span><span class="pyg-p">.</span><span class="pyg-n">appendChild</span><span class="pyg-p">(</span><span class="pyg-n">paperElem</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L80" href="#L80">80</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L81" href="#L81">81</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">doc</span><span class="pyg-p">.</span><span class="pyg-n">toByteArray</span><span class="pyg-p">(</span><span class="pyg-n">indent</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L82" href="#L82">82</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr>
</table>
</div>
</div>
<p class="fl">Loggerhead 1.17 is a web-based interface for <a href="http://bazaar-vcs.org/">Bazaar</a> branches</p>
</div>
</body>
</html>