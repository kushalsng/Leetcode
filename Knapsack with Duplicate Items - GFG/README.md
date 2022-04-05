# Knapsack with Duplicate Items
## Easy 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a set of <strong>N</strong> items, each with a weight and a value, represented by the array <strong>w[]</strong>&nbsp;and&nbsp;<strong>val[]</strong>&nbsp;respectively.&nbsp;Also, a knapsack with weight limit <strong>W</strong>.<br>
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.<br>
Note: Each item can be taken any number of times.</span></p>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total 
 &nbsp;weight = 1 + 1 + 1  = 3 which is &lt;= W.</span>
</pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
<strong>Output:</strong> 11
<strong>Explanation:</strong> The optimal choice is to 
pick the 2nd and 4th element.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input&nbsp;or print anything. Your task is to complete the function <strong>knapSack()</strong> which takes the values N, W and the arrays val[] and wt[] as input parameters and returns the maximum possible&nbsp;value.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N*W)<br>
<strong>Expected Auxiliary Space: </strong>O(W)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N, W ≤ 1000<br>
1 ≤ val[i], wt[i] ≤ 100</span></p>
 <p></p>
            </div>