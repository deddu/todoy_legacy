<?xml version="1.0"?>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
<meta content="Loggerhead/1.17 Python/2.6.5 Bazaar/2.2.0 Paste/1.7.2 PasteDeploy/1.3.3 SimpleTAL/4.1 Pygments/1.2.2 simplejson/2.0.9" name="generator" />
<title>~benlau/penpen/trunk : contents of src/libpenpen/ppgraphicsstroke.cpp at revision 78</title>
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
/<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78?file_id=src-20100614163637-a9u616hzyeh125l5-1">src</a>/<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/files/78?file_id=libpenpen-20100725033312-lcpnhscm51x8wpur-1">libpenpen</a>/ppgraphicsstroke.cpp
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
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/changes?filter_file_id=graphicsstroke.cpp-20100614163637-a9u616hzyeh125l5-12">view changes to this file</a>
</li>
<li id="last">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/download/head%3A/graphicsstroke.cpp-20100614163637-a9u616hzyeh125l5-12/ppgraphicsstroke.cpp">download file</a>
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
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QtCore&gt;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L2" href="#L2">2</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QPainter&gt;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L3" href="#L3">3</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QEvent&gt;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L4" href="#L4">4</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &lt;QGraphicsSceneEvent&gt;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L5" href="#L5">5</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#include &quot;ppgraphicsstroke.h&quot;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L6" href="#L6">6</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L7" href="#L7">7</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-p">(</span><span class="pyg-n">QGraphicsItem</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-n">parent</span><span class="pyg-p">)</span><span class="pyg-"> </span><span class="pyg-o">:</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L8" href="#L8">8</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/55" title="55 by Ben Lau, on 28 Jul 2010 12:20 (2010-07-28 12:20:29)">55</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QGraphicsItem</span><span class="pyg-p">(</span><span class="pyg-mi">0</span><span class="pyg-p">)</span><span class="pyg-"> </span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-n">m_id</span><span class="pyg-p">(</span><span class="pyg-mi">0</span><span class="pyg-p">)</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L9" href="#L9">9</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L10" href="#L10">10</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_pen</span><span class="pyg-p">.</span><span class="pyg-n">setColor</span><span class="pyg-p">(</span><span class="pyg-n">Qt</span><span class="pyg-o">::</span><span class="pyg-n">red</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L11" href="#L11">11</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_pen</span><span class="pyg-p">.</span><span class="pyg-n">setStyle</span><span class="pyg-p">(</span><span class="pyg-n">Qt</span><span class="pyg-o">::</span><span class="pyg-n">SolidLine</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L12" href="#L12">12</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/17" title="17 by Ben Lau, on 19 Jun 2010 14:45 (2010-06-19 14:45:08)">17</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_pen</span><span class="pyg-p">.</span><span class="pyg-n">setCapStyle</span><span class="pyg-p">(</span><span class="pyg-n">Qt</span><span class="pyg-o">::</span><span class="pyg-n">RoundCap</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L13" href="#L13">13</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_pen</span><span class="pyg-p">.</span><span class="pyg-n">setJoinStyle</span><span class="pyg-p">(</span><span class="pyg-n">Qt</span><span class="pyg-o">::</span><span class="pyg-n">RoundJoin</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L14" href="#L14">14</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_pen</span><span class="pyg-p">.</span><span class="pyg-n">setWidth</span><span class="pyg-p">(</span><span class="pyg-mi">3</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L15" href="#L15">15</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/55" title="55 by Ben Lau, on 28 Jul 2010 12:20 (2010-07-28 12:20:29)">55</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L16" href="#L16">16</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">if</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-n">parent</span><span class="pyg-o">!=</span><span class="pyg-mi">0</span><span class="pyg-p">)</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L17" href="#L17">17</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">setParentItem</span><span class="pyg-p">(</span><span class="pyg-n">parent</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L18" href="#L18">18</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L19" href="#L19">19</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L20" href="#L20">20</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">paint</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-"> </span><span class="pyg-n">QPainter</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-"> </span><span class="pyg-n">painter</span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-k">const</span><span class="pyg-"> </span><span class="pyg-n">QStyleOptionGraphicsItem</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-"> </span><span class="pyg-n">option</span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-n">QWidget</span><span class="pyg-"> </span><span class="pyg-o">*</span><span class="pyg-"> </span><span class="pyg-n">widget</span><span class="pyg-"> </span><span class="pyg-p">)</span><span class="pyg-">  </span><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L21" href="#L21">21</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">Q_UNUSED</span><span class="pyg-p">(</span><span class="pyg-n">option</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L22" href="#L22">22</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">Q_UNUSED</span><span class="pyg-p">(</span><span class="pyg-n">widget</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L23" href="#L23">23</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L24" href="#L24">24</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">if</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-n">m_polygon</span><span class="pyg-p">.</span><span class="pyg-n">size</span><span class="pyg-p">()</span><span class="pyg-"> </span><span class="pyg-o">&gt;</span><span class="pyg-"> </span><span class="pyg-mi">0</span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L25" href="#L25">25</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">painter</span><span class="pyg-o">-&gt;</span><span class="pyg-n">save</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L26" href="#L26">26</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/17" title="17 by Ben Lau, on 19 Jun 2010 14:45 (2010-06-19 14:45:08)">17</a>
</td>
<td class="annoCont"><pre><span class="pyg-c1">//        qDebug() &lt;&lt; __func__ &lt;&lt; m_pen.joinStyle() &lt;&lt; m_pen.capStyle();</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L27" href="#L27">27</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/8" title="8 by Ben Lau, on 17 Jun 2010 14:17 (2010-06-17 14:17:59)">8</a>
</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">painter</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setRenderHint</span><span class="pyg-p">(</span><span class="pyg-n">QPainter</span><span class="pyg-o">::</span><span class="pyg-n">Antialiasing</span><span class="pyg-"> </span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-kc">true</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L28" href="#L28">28</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L29" href="#L29">29</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">painter</span><span class="pyg-o">-&gt;</span><span class="pyg-n">setPen</span><span class="pyg-p">(</span><span class="pyg-n">m_pen</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L30" href="#L30">30</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/17" title="17 by Ben Lau, on 19 Jun 2010 14:45 (2010-06-19 14:45:08)">17</a>
</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">painter</span><span class="pyg-o">-&gt;</span><span class="pyg-n">drawPolyline</span><span class="pyg-p">(</span><span class="pyg-n">m_polygon</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L31" href="#L31">31</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L32" href="#L32">32</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">painter</span><span class="pyg-o">-&gt;</span><span class="pyg-n">restore</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L33" href="#L33">33</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L34" href="#L34">34</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L35" href="#L35">35</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L36" href="#L36">36</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">QRectF</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">boundingRect</span><span class="pyg-p">()</span><span class="pyg-"> </span><span class="pyg-k">const</span><span class="pyg-"> </span><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L37" href="#L37">37</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">m_boundingRect</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L38" href="#L38">38</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L39" href="#L39">39</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L40" href="#L40">40</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">QPainterPath</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">shape</span><span class="pyg-"> </span><span class="pyg-p">()</span><span class="pyg-"> </span><span class="pyg-k">const</span><span class="pyg-"> </span><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L41" href="#L41">41</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QPainterPath</span><span class="pyg-"> </span><span class="pyg-n">path</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L42" href="#L42">42</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">path</span><span class="pyg-p">.</span><span class="pyg-n">addPolygon</span><span class="pyg-p">(</span><span class="pyg-n">m_polygon</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L43" href="#L43">43</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">path</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L44" href="#L44">44</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L45" href="#L45">45</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L46" href="#L46">46</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/55" title="55 by Ben Lau, on 28 Jul 2010 12:20 (2010-07-28 12:20:29)">55</a>
</td>
<td class="annoCont"><pre><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">setId</span><span class="pyg-p">(</span><span class="pyg-kt">int</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L47" href="#L47">47</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_id</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L48" href="#L48">48</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">setZValue</span><span class="pyg-p">(</span><span class="pyg-n">m_id</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L49" href="#L49">49</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L50" href="#L50">50</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L51" href="#L51">51</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-kt">int</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">id</span><span class="pyg-p">(){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L52" href="#L52">52</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">m_id</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L53" href="#L53">53</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L54" href="#L54">54</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L55" href="#L55">55</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L56" href="#L56">56</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/40" title="40 by Ben Lau, on 25 Jul 2010 05:31 (2010-07-25 05:31:42)">40</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#if 0</span><span class="pyg-c"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L57" href="#L57">57</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">QString GraphicsStroke::tagName(){</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L58" href="#L58">58</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    return &quot;stroke&quot;;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L59" href="#L59">59</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">}</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L60" href="#L60">60</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L61" href="#L61">61</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">QDomElement GraphicsStroke::createDomElement(QDomDocument &amp;doc){</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L62" href="#L62">62</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    QDomElement element = doc.createElement(tagName());</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L63" href="#L63">63</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L64" href="#L64">64</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    QStringList list;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L65" href="#L65">65</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    QVector&lt;QPointF&gt; pts = points();</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L66" href="#L66">66</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    foreach (QPointF pt , pts) {</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L67" href="#L67">67</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">        QString str = QString(&quot;%1,%2&quot;).arg(pt.x()).arg(pt.y());</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L68" href="#L68">68</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">        list &lt;&lt; str;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L69" href="#L69">69</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    }</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L70" href="#L70">70</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L71" href="#L71">71</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    element.setAttribute(&quot;points&quot;,list.join(&quot; &quot;));</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L72" href="#L72">72</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    element.setAttribute(&quot;color&quot;,m_pen.color().name());</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L73" href="#L73">73</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    element.setAttribute(&quot;width&quot;,m_pen.width());</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L74" href="#L74">74</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    return element;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L75" href="#L75">75</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">}</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L76" href="#L76">76</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L77" href="#L77">77</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">bool GraphicsStroke::setFromDomElement(QDomElement &amp;elem){</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L78" href="#L78">78</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    if (elem.tagName() != tagName())</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L79" href="#L79">79</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">        return false;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L80" href="#L80">80</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L81" href="#L81">81</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/30" title="30 by Ben Lau, on 20 Jul 2010 14:21 (2010-07-20 14:21:11)">30</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">    prepareGeometryChange();</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L82" href="#L82">82</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L83" href="#L83">83</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">    clear();</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L84" href="#L84">84</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    QString color = elem.attribute(&quot;color&quot;,&quot;#000000&quot;);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L85" href="#L85">85</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    QColor c(color);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L86" href="#L86">86</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    m_pen.setColor(c);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L87" href="#L87">87</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L88" href="#L88">88</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    int width = elem.attribute(&quot;width&quot;,&quot;1&quot;).toInt();</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L89" href="#L89">89</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    m_pen.setWidth(width);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L90" href="#L90">90</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L91" href="#L91">91</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    QString val = elem.attribute(&quot;points&quot;,&quot;&quot;);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L92" href="#L92">92</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    QStringList list = val.split(&quot; &quot;);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L93" href="#L93">93</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L94" href="#L94">94</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">//    QVector&lt;QPointF&gt; pts;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L95" href="#L95">95</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/17" title="17 by Ben Lau, on 19 Jun 2010 14:45 (2010-06-19 14:45:08)">17</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">//    QPointF last;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L96" href="#L96">96</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L97" href="#L97">97</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    for (int i = 0 ; i &lt; list.size() ; i++) {</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L98" href="#L98">98</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">        QStringList xy = list.at(i).split(&quot;,&quot;);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L99" href="#L99">99</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L100" href="#L100">100</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">        if (xy.size() == 2) {</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L101" href="#L101">101</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">            qreal x = xy.at(0).toFloat();</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L102" href="#L102">102</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">            qreal y = xy.at(1).toFloat();</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L103" href="#L103">103</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">            QPointF pt(x,y);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L104" href="#L104">104</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L105" href="#L105">105</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/17" title="17 by Ben Lau, on 19 Jun 2010 14:45 (2010-06-19 14:45:08)">17</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">            append(pt,false);</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L106" href="#L106">106</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">            /*</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L107" href="#L107">107</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">            if (i != 0) {</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L108" href="#L108">108</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">                append(last,false);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L109" href="#L109">109</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">                append(pt,false);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L110" href="#L110">110</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">            } else {</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L111" href="#L111">111</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">                append(pt,false);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L112" href="#L112">112</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">                append(pt,false);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L113" href="#L113">113</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">            }</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L114" href="#L114">114</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/17" title="17 by Ben Lau, on 19 Jun 2010 14:45 (2010-06-19 14:45:08)">17</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L115" href="#L115">115</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">            last = pt;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L116" href="#L116">116</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/17" title="17 by Ben Lau, on 19 Jun 2010 14:45 (2010-06-19 14:45:08)">17</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">            */</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L117" href="#L117">117</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">        }</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L118" href="#L118">118</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L119" href="#L119">119</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    }</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L120" href="#L120">120</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L121" href="#L121">121</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    updateBoundingRect();</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L122" href="#L122">122</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">    return true;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L123" href="#L123">123</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">}</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L124" href="#L124">124</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/40" title="40 by Ben Lau, on 25 Jul 2010 05:31 (2010-07-25 05:31:42)">40</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#endif</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L125" href="#L125">125</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L126" href="#L126">126</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">QPolygonF</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">polygon</span><span class="pyg-p">(){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L127" href="#L127">127</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">m_polygon</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L128" href="#L128">128</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L129" href="#L129">129</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L130" href="#L130">130</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">setPolygon</span><span class="pyg-p">(</span><span class="pyg-n">QPolygonF</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L131" href="#L131">131</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/30" title="30 by Ben Lau, on 20 Jul 2010 14:21 (2010-07-20 14:21:11)">30</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">prepareGeometryChange</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L132" href="#L132">132</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L133" href="#L133">133</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_polygon</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L134" href="#L134">134</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">updateBoundingRect</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L135" href="#L135">135</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L136" href="#L136">136</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L137" href="#L137">137</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">QVector</span><span class="pyg-o">&lt;</span><span class="pyg-n">QPointF</span><span class="pyg-o">&gt;</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">points</span><span class="pyg-p">(){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L138" href="#L138">138</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QVector</span><span class="pyg-"> </span><span class="pyg-o">&lt;</span><span class="pyg-n">QPointF</span><span class="pyg-o">&gt;</span><span class="pyg-"> </span><span class="pyg-n">res</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L139" href="#L139">139</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-kt">int</span><span class="pyg-"> </span><span class="pyg-n">n</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">m_polygon</span><span class="pyg-p">.</span><span class="pyg-n">size</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L140" href="#L140">140</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">if</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-n">n</span><span class="pyg-"> </span><span class="pyg-o">&gt;</span><span class="pyg-"> </span><span class="pyg-mi">0</span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L141" href="#L141">141</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">QPointF</span><span class="pyg-"> </span><span class="pyg-n">prev</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">m_polygon</span><span class="pyg-p">.</span><span class="pyg-n">at</span><span class="pyg-p">(</span><span class="pyg-mi">0</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L142" href="#L142">142</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">res</span><span class="pyg-"> </span><span class="pyg-o">&lt;&lt;</span><span class="pyg-"> </span><span class="pyg-n">prev</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L143" href="#L143">143</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L144" href="#L144">144</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/17" title="17 by Ben Lau, on 19 Jun 2010 14:45 (2010-06-19 14:45:08)">17</a>
</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-k">for</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-kt">int</span><span class="pyg-"> </span><span class="pyg-n">i</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-mi">1</span><span class="pyg-"> </span><span class="pyg-p">;</span><span class="pyg-"> </span><span class="pyg-n">i</span><span class="pyg-o">&lt;</span><span class="pyg-"> </span><span class="pyg-n">n</span><span class="pyg-"> </span><span class="pyg-p">;</span><span class="pyg-n">i</span><span class="pyg-o">++</span><span class="pyg-p">){</span><span class="pyg-"> </span><span class="pyg-c1">// Remove duplicated points</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L145" href="#L145">145</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">            </span><span class="pyg-n">QPointF</span><span class="pyg-"> </span><span class="pyg-n">pt</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">m_polygon</span><span class="pyg-p">.</span><span class="pyg-n">at</span><span class="pyg-p">(</span><span class="pyg-n">i</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L146" href="#L146">146</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c1">//            qDebug() &lt;&lt; prev &lt;&lt; pt ;</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L147" href="#L147">147</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">            </span><span class="pyg-k">if</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-n">pt</span><span class="pyg-o">!=</span><span class="pyg-"> </span><span class="pyg-n">prev</span><span class="pyg-p">)</span><span class="pyg-"> </span><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L148" href="#L148">148</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c1">//            if ( !(pt.x() == prev.x() &amp;&amp; pt.y() == prev.y())){</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L149" href="#L149">149</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">                </span><span class="pyg-n">res</span><span class="pyg-"> </span><span class="pyg-o">&lt;&lt;</span><span class="pyg-"> </span><span class="pyg-n">pt</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L150" href="#L150">150</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">                </span><span class="pyg-n">prev</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">pt</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L151" href="#L151">151</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">            </span><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L152" href="#L152">152</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L153" href="#L153">153</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L154" href="#L154">154</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L155" href="#L155">155</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">res</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L156" href="#L156">156</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L157" href="#L157">157</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L158" href="#L158">158</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L159" href="#L159">159</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">append</span><span class="pyg-p">(</span><span class="pyg-k">const</span><span class="pyg-"> </span><span class="pyg-n">QPointF</span><span class="pyg-"> </span><span class="pyg-n">pt</span><span class="pyg-p">,</span><span class="pyg-kt">bool</span><span class="pyg-"> </span><span class="pyg-n">refresh</span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L160" href="#L160">160</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/30" title="30 by Ben Lau, on 20 Jul 2010 14:21 (2010-07-20 14:21:11)">30</a>
</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L161" href="#L161">161</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_polygon</span><span class="pyg-p">.</span><span class="pyg-n">append</span><span class="pyg-p">(</span><span class="pyg-n">pt</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L162" href="#L162">162</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L163" href="#L163">163</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/20" title="20 by Ben Lau, on 28 Jun 2010 14:57 (2010-06-28 14:57:08)">20</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">if</span><span class="pyg-"> </span><span class="pyg-p">(</span><span class="pyg-n">refresh</span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L164" href="#L164">164</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/31" title="31 by Ben Lau, on 21 Jul 2010 13:38 (2010-07-21 13:38:37)">31</a>
</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">prepareGeometryChange</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L165" href="#L165">165</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L166" href="#L166">166</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/35" title="35 by Ben Lau, on 23 Jul 2010 17:24 (2010-07-23 17:24:57)">35</a>
</td>
<td class="annoCont"><pre><span class="pyg-cp">#if 0</span><span class="pyg-c"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L167" href="#L167">167</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/20" title="20 by Ben Lau, on 28 Jun 2010 14:57 (2010-06-28 14:57:08)">20</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">        qreal x1,y1,x2,y2;</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L168" href="#L168">168</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">        m_boundingRect.getCoords(&amp;x1,&amp;y1,&amp;x2,&amp;y2);</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L169" href="#L169">169</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">        m_boundingRect.setCoords(qMin&lt;qreal&gt;(x1,pt.x()),</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L170" href="#L170">170</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">                                 qMin&lt;qreal&gt;(y1,pt.y()),</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L171" href="#L171">171</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">                                 qMax&lt;qreal&gt;(x2,pt.x()),</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L172" href="#L172">172</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">                                 qMax&lt;qreal&gt;(y2,pt.y()));</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L173" href="#L173">173</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/35" title="35 by Ben Lau, on 23 Jul 2010 17:24 (2010-07-23 17:24:57)">35</a>
</td>
<td class="annoCont"><pre><span class="pyg-c">#else</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L174" href="#L174">174</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-c">        updateBoundingRect();</span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L175" href="#L175">175</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-cp">#endif</span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L176" href="#L176">176</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/20" title="20 by Ben Lau, on 28 Jun 2010 14:57 (2010-06-28 14:57:08)">20</a>
</td>
<td class="annoCont"><pre><span class="pyg-">        </span><span class="pyg-n">update</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L177" href="#L177">177</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L178" href="#L178">178</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L179" href="#L179">179</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L180" href="#L180">180</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">clear</span><span class="pyg-p">()</span><span class="pyg-"> </span><span class="pyg-p">{</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L181" href="#L181">181</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/30" title="30 by Ben Lau, on 20 Jul 2010 14:21 (2010-07-20 14:21:11)">30</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">prepareGeometryChange</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L182" href="#L182">182</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L183" href="#L183">183</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_polygon</span><span class="pyg-p">.</span><span class="pyg-n">clear</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L184" href="#L184">184</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">updateBoundingRect</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L185" href="#L185">185</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L186" href="#L186">186</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L187" href="#L187">187</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">setPen</span><span class="pyg-p">(</span><span class="pyg-k">const</span><span class="pyg-"> </span><span class="pyg-n">QPen</span><span class="pyg-o">&amp;</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L188" href="#L188">188</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_pen</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">val</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L189" href="#L189">189</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L190" href="#L190">190</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L191" href="#L191">191</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-n">QPen</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">pen</span><span class="pyg-p">(){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L192" href="#L192">192</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-k">return</span><span class="pyg-"> </span><span class="pyg-n">m_pen</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L193" href="#L193">193</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-p">}</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L194" href="#L194">194</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L195" href="#L195">195</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/50" title="50 by Ben Lau, on 27 Jul 2010 06:25 (2010-07-27 06:25:41)">50</a>
</td>
<td class="annoCont"><pre><span class="pyg-kt">void</span><span class="pyg-"> </span><span class="pyg-n">PPGraphicsStroke</span><span class="pyg-o">::</span><span class="pyg-n">updateBoundingRect</span><span class="pyg-p">(){</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L196" href="#L196">196</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/48" title="48 by Ben Lau, on 26 Jul 2010 14:26 (2010-07-26 14:26:21)">48</a>
</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QRectF</span><span class="pyg-"> </span><span class="pyg-n">rect</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">m_polygon</span><span class="pyg-p">.</span><span class="pyg-n">boundingRect</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L197" href="#L197">197</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QPointF</span><span class="pyg-"> </span><span class="pyg-n">tf</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">rect</span><span class="pyg-p">.</span><span class="pyg-n">topLeft</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L198" href="#L198">198</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QPointF</span><span class="pyg-"> </span><span class="pyg-n">br</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">rect</span><span class="pyg-p">.</span><span class="pyg-n">bottomRight</span><span class="pyg-p">();</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L199" href="#L199">199</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L200" href="#L200">200</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">QPointF</span><span class="pyg-"> </span><span class="pyg-n">d</span><span class="pyg-p">(</span><span class="pyg-n">m_pen</span><span class="pyg-p">.</span><span class="pyg-n">width</span><span class="pyg-p">()</span><span class="pyg-"> </span><span class="pyg-p">,</span><span class="pyg-"> </span><span class="pyg-n">m_pen</span><span class="pyg-p">.</span><span class="pyg-n">width</span><span class="pyg-p">());</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L201" href="#L201">201</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">tf</span><span class="pyg-"> </span><span class="pyg-o">-=</span><span class="pyg-"> </span><span class="pyg-n">d</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L202" href="#L202">202</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">br</span><span class="pyg-"> </span><span class="pyg-o">+=</span><span class="pyg-"> </span><span class="pyg-n">d</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L203" href="#L203">203</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">rect</span><span class="pyg-p">.</span><span class="pyg-n">setTopLeft</span><span class="pyg-p">(</span><span class="pyg-n">tf</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L204" href="#L204">204</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">rect</span><span class="pyg-p">.</span><span class="pyg-n">setBottomRight</span><span class="pyg-p">(</span><span class="pyg-n">br</span><span class="pyg-p">);</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L205" href="#L205">205</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre></pre></td>
</tr><tr class="blueRow0">
<td class="annoLine"><a id="L206" href="#L206">206</a></td>
<td class="annoRev">

</td>
<td class="annoCont"><pre><span class="pyg-">    </span><span class="pyg-n">m_boundingRect</span><span class="pyg-"> </span><span class="pyg-o">=</span><span class="pyg-"> </span><span class="pyg-n">rect</span><span class="pyg-p">;</span><span class="pyg-"></span></pre></td>
</tr><tr class="blueRow1">
<td class="annoLine"><a id="L207" href="#L207">207</a></td>
<td class="annoRev">
<a href="http://bazaar.launchpad.net/%7Ebenlau/penpen/trunk/revision/1" title="1 by Ben Lau, on 14 Jun 2010 16:36 (2010-06-14 16:36:55)">1</a>
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