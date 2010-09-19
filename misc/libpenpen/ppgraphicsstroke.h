<?xml version="1.0"?>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<meta content="Loggerhead/1.17 Python/2.6.5 Bazaar/2.2.0 Paste/1.7.2 PasteDeploy/1.3.3 SimpleTAL/4.1 Pygments/1.2.2 simplejson/2.0.9" name="generator" />
<title>~benlau/penpen/trunk : contents of src/libpenpen/ppgraphicsstroke.h at revision 78</title>
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
/<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78?file_id=src-20100614163637-a9u616hzyeh125l5-1">src</a>/<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78?file_id=libpenpen-20100725033312-lcpnhscm51x8wpur-1">libpenpen</a>/ppgraphicsstroke.h
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
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/changes?filter_file_id=graphicsstroke.h-20100614163637-a9u616hzyeh125l5-13">view changes to this file</a>
</li>
<li id="last">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/download/head%3A/graphicsstroke.h-20100614163637-a9u616hzyeh125l5-13/ppgraphicsstroke.h">download file</a>
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
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#ifndef PPGRAPHICSSTROKE_H</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L2" href="#L2">2</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#define PPGRAPHICSSTROKE_H</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L3" href="#L3">3</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L4" href="#L4">4</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QGraphicsObject&gt;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L5" href="#L5">5</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QPolygon&gt;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L6" href="#L6">6</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QPen&gt;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L7" href="#L7">7</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L8" href="#L8">8</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/56" title="56 by Ben Lau, on 29 Jul 2010 17:03 (2010-07-29 17:03:56)">56</a>
</td>
<td class="annoCont"><pre><span class="pyg-c1">/// Stroke graphical item</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L9" href="#L9">9</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L10" href="#L10">10</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">class</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-"> </span><span class="pyg-o">:</span><span class="pyg-"> </span><span class="pyg-n">public</span><span class="pyg-"> </span><span class="pyg-n">QGraphicsItem</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L11" href="#L11">11</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L12" href="#L12">12</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-nl">public:</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L13" href="#L13">13</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">explicit</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-p">(</span><span class="pyg-n">QGraphicsItem</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">parent</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-mi">0</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L14" href="#L14">14</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L15" href="#L15">15</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">virtual</span><span class="pyg-"> </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-nf">paint</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-"> </span><span class="pyg-n">QPainter</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-"> </span><span class="pyg-n">painter</span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-k">const</span><span class="pyg-"> </span><span class="pyg-n">QStyleOptionGraphicsItem</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-"> </span><span class="pyg-n">option</span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-n">QWidget</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-"> </span><span class="pyg-n">widget</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-mi">0</span><span class="pyg-"> </span><span class="pyg-p">)</span><span class="pyg-">  </span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L16" href="#L16">16</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">virtual</span><span class="pyg-"> </span><span class="pyg-n">QRectF</span><span class="pyg-"> </span><span class="pyg-n">boundingRect</span><span class="pyg-p">()</span><span class="pyg-"> </span><span class="pyg-k">const</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L17" href="#L17">17</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">virtual</span><span class="pyg-"> </span><span class="pyg-n">QPainterPath</span><span class="pyg-"> </span><span class="pyg-n">shape</span><span class="pyg-"> </span><span class="pyg-p">()</span><span class="pyg-"> </span><span class="pyg-k">const</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L18" href="#L18">18</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L19" href="#L19">19</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/30" title="30 by Ben Lau, on 20 Jul 2010 14:21 (2010-07-20 14:21:11)">30</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-c1">// XmlIOIface interfaces</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L20" href="#L20">20</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/40" title="40 by Ben Lau, on 25 Jul 2010 05:31 (2010-07-25 05:31:42)">40</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-cm">/*</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L21" href="#L21">21</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-cm">    virtual QString tagName();</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L22" href="#L22">22</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">    virtual QDomElement createDomElement(QDomDocument &amp;doc);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L23" href="#L23">23</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">    virtual bool setFromDomElement(QDomElement &amp;elem);</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L24" href="#L24">24</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/40" title="40 by Ben Lau, on 25 Jul 2010 05:31 (2010-07-25 05:31:42)">40</a>
</td>
<td class="annoCont"><pre><span class="pyg-cm">    */</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L25" href="#L25">25</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/55" title="55 by Ben Lau, on 28 Jul 2010 12:20 (2010-07-28 12:20:29)">55</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-c1">/// Set the ID of the stroke.</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L26" href="#L26">26</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-cm">/**</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L27" href="#L27">27</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">      Usually you don&#39;t set by yourself. Whatever a stroke</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L28" href="#L28">28</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">      with ID equal to zero added to a PPPaper. It&#39;s ID</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L29" href="#L29">29</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">      will be assigned automatically. The ID should be</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L30" href="#L30">30</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">      unique within the paper</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L31" href="#L31">31</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L32" href="#L32">32</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">      @param val The ID of the stroke. The value should be greater than 0.</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L33" href="#L33">33</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">      @remarks The ID is also eqaul to the zorder of the object.</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L34" href="#L34">34</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cm">     */</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L35" href="#L35">35</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">setId</span><span class="pyg-p">(</span><span class="pyg-kt">int</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L36" href="#L36">36</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">int</span><span class="pyg-"> </span><span class="pyg-n">id</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L37" href="#L37">37</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L38" href="#L38">38</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QPolygonF</span><span class="pyg-"> </span><span class="pyg-n">polygon</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L39" href="#L39">39</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">setPolygon</span><span class="pyg-p">(</span><span class="pyg-n">QPolygonF</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L40" href="#L40">40</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L41" href="#L41">41</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-c1">/// Simplifed polygon with duplicated points removed</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L42" href="#L42">42</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QVector</span><span class="pyg-o">&lt;</span><span class="pyg-n">QPointF</span><span class="pyg-o">&gt;</span><span class="pyg-"> </span><span class="pyg-n">points</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L43" href="#L43">43</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L44" href="#L44">44</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/48" title="48 by Ben Lau, on 26 Jul 2010 14:26 (2010-07-26 14:26:21)">48</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">append</span><span class="pyg-p">(</span><span class="pyg-k">const</span><span class="pyg-"> </span><span class="pyg-n">QPointF</span><span class="pyg-"> </span><span class="pyg-n">pt</span><span class="pyg-p">,</span><span class="pyg-n">bool</span><span class="pyg-"> </span><span class="pyg-n">refresh</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-nb">true</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L45" href="#L45">45</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L46" href="#L46">46</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">clear</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L47" href="#L47">47</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L48" href="#L48">48</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">setPen</span><span class="pyg-p">(</span><span class="pyg-k">const</span><span class="pyg-"> </span><span class="pyg-n">QPen</span><span class="pyg-o">&amp;</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L49" href="#L49">49</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QPen</span><span class="pyg-"> </span><span class="pyg-n">pen</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L50" href="#L50">50</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L51" href="#L51">51</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-nl">private:</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L52" href="#L52">52</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">updateBoundingRect</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L53" href="#L53">53</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L54" href="#L54">54</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QPen</span><span class="pyg-"> </span><span class="pyg-n">m_pen</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L55" href="#L55">55</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QPolygonF</span><span class="pyg-"> </span><span class="pyg-n">m_polygon</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L56" href="#L56">56</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L57" href="#L57">57</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QRectF</span><span class="pyg-"> </span><span class="pyg-n">m_boundingRect</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L58" href="#L58">58</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L59" href="#L59">59</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/55" title="55 by Ben Lau, on 28 Jul 2010 12:20 (2010-07-28 12:20:29)">55</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">int</span><span class="pyg-"> </span><span class="pyg-n">m_id</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L60" href="#L60">60</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-p">};</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L61" href="#L61">61</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L62" href="#L62">62</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">QDebug</span><span class="pyg-"> </span><span class="pyg-n">operator</span><span class="pyg-o">&lt;&lt;</span><span class="pyg-p">(</span><span class="pyg-n">QDebug</span><span class="pyg-"> </span><span class="pyg-n">dbg</span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-"> </span><span class="pyg-o">&amp;</span><span class="pyg-n">stroke</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L63" href="#L63">63</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L64" href="#L64">64</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#endif </span><span class="pyg-c1">// FVGRAPHICSSTROKE_H</span></pre></td>
</tr>
</table>
</div>
</div>
<p class="fl">Loggerhead 1.17 is a web-based interface for <a href="http://bazaar-vcs.org/">Bazaar</a> branches</p>
</div>
</body>
</html>