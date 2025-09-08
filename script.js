// DSA Topics Data
const topicsData = [
    {
        name: "Arrays",
        icon: "fas fa-list",
        description: "Master array manipulation, searching, sorting, and advanced algorithms like Kadane's Algorithm and Two Pointers technique.",
        problems: [
            "Best Time to Buy and Sell Stock",
            "Collecting Water",
            "Container With Most Water", 
            "Count Inversion",
            "First Missing Positive",
            "Kadane Algorithm",
            "Longest Consecutive Sequence",
            "Majority Element",
            "Maximum Product Subarray",
            "Maximum Subarray Sum",
            "Moore's Voting Algorithm",
            "Repeating And Missing Number",
            "Rotate Array",
            "Split Array Largest Sum",
            "The Celebrity Problem",
            "Trapping Rain Water II"
        ],
        category: "arrays"
    },
    {
        name: "Binary Search",
        icon: "fas fa-search",
        description: "Learn binary search variations, search in rotated arrays, and advanced binary search applications.",
        problems: [
            "Aggressive Cows",
            "Find Peak Index",
            "Koko Eating Bananas",
            "Lowest Common Ancestor in BST",
            "Search in Rotated Sorted Array",
            "Split Array Largest Sum"
        ],
        category: "binary"
    },
    {
        name: "Binary Trees",
        icon: "fas fa-sitemap",
        description: "Explore tree traversals, path problems, serialization, and advanced tree algorithms.",
        problems: [
            "Binary Tree Right Side View",
            "Binary Tree Maximum Path Sum",
            "Inorder Traversal",
            "Kth Smallest Element in BST",
            "Serialize and Deserialize Binary Tree",
            "Two Sum in BST"
        ],
        category: "trees"
    },
    {
        name: "Dynamic Programming",
        icon: "fas fa-project-diagram",
        description: "Master DP patterns including 1D DP, 2D DP, subsequences, strings, and grid problems.",
        problems: [
            "1D DP Problems",
            "DP on Grids",
            "DP on Strings", 
            "DP on Subsequences",
            "Regular Expression Matching"
        ],
        category: "dp"
    },
    {
        name: "Graphs",
        icon: "fas fa-project-diagram",
        description: "Learn graph algorithms including cycle detection, shortest paths, MST, and advanced graph problems.",
        problems: [
            "Detect Cycle in Directed Graph",
            "Detect Cycle in Undirected Graph",
            "Dijkstra Algorithm",
            "Find City with Smallest Neighbors",
            "Minimum Spanning Tree",
            "Securing the City"
        ],
        category: "graphs"
    },
    {
        name: "Strings",
        icon: "fas fa-font",
        description: "Master string manipulation, palindromes, anagrams, and advanced string algorithms.",
        problems: [
            "Check if String is Palindrome",
            "Isomorphic String",
            "Longest Palindromic Substring",
            "Remove Duplicate Letters",
            "Reverse String",
            "String to Integer",
            "Valid Anagram",
            "Z-Algorithm"
        ],
        category: "strings"
    },
    {
        name: "Linked Lists",
        icon: "fas fa-link",
        description: "Learn linked list operations, reversals, and advanced linked list problems.",
        problems: [
            "Reverse Nodes in k-Group",
            "Reversing a Doubly Linked List"
        ],
        category: "linked"
    },
    {
        name: "Stack and Queue",
        icon: "fas fa-layer-group",
        description: "Master stack and queue operations, parentheses matching, and advanced applications.",
        problems: [
            "Calculator with Parentheses",
            "Longest Rectangle in Histogram",
            "Valid Parentheses"
        ],
        category: "stack"
    },
    {
        name: "Sorting",
        icon: "fas fa-sort",
        description: "Learn various sorting algorithms and their applications in problem solving.",
        problems: [
            "Merging Two Sorted Arrays",
            "Sort 0's, 1's, and 2's",
            "Sorting Algorithms"
        ],
        category: "sorting"
    },
    {
        name: "Hashing",
        icon: "fas fa-key",
        description: "Master hash tables, frequency counting, and hash-based problem solving techniques.",
        problems: [
            "Find Duplicate Number",
            "Group Anagrams"
        ],
        category: "hashing"
    },
    {
        name: "Two Pointers",
        icon: "fas fa-hand-point-up",
        description: "Learn two-pointer technique for array and string problems.",
        problems: [
            "3Sum",
            "3Sum Closest",
            "Smallest Range Covering Elements",
            "Triplet Sum in Array"
        ],
        category: "pointers"
    },
    {
        name: "Sliding Window",
        icon: "fas fa-window-maximize",
        description: "Master sliding window technique for substring and subarray problems.",
        problems: [
            "Count Nice Subarray",
            "Fruits and Baskets",
            "Longest Substring Without Repeating Characters",
            "Max Consecutive Ones 3",
            "Sliding Window Maximum"
        ],
        category: "sliding"
    },
    {
        name: "Greedy",
        icon: "fas fa-bullseye",
        description: "Learn greedy algorithms and their applications in optimization problems.",
        problems: [
            "Candy",
            "Jump Game",
            "Minimum Number of Refueling Stops"
        ],
        category: "greedy"
    },
    {
        name: "Recursion and Backtracking",
        icon: "fas fa-undo",
        description: "Master recursion, backtracking, and combinatorial problem solving.",
        problems: [
            "Burst Balloon",
            "Find All Subsets",
            "Letter Combination of Phone Number",
            "Levenshtein Algorithm",
            "N-Queens Backtracking"
        ],
        category: "recursion"
    },
    {
        name: "Matrix",
        icon: "fas fa-th",
        description: "Learn matrix operations, rotations, and advanced matrix algorithms.",
        problems: [
            "Diagonal Sum",
            "Longest Increasing Path in Matrix",
            "Rotate Matrix",
            "Set Matrix Zeroes",
            "Spiral Matrix",
            "Transpose of Matrix",
            "Word Search"
        ],
        category: "matrix"
    },
    {
        name: "Math",
        icon: "fas fa-calculator",
        description: "Master mathematical algorithms, number theory, and computational problems.",
        problems: [
            "Champions League",
            "Even or Odd",
            "Palindrome Number",
            "Reverse Integer",
            "Sieve of Eratosthenes",
            "Sum of Good Numbers"
        ],
        category: "math"
    },
    {
        name: "Bit Manipulation",
        icon: "fas fa-microchip",
        description: "Learn bitwise operations and their applications in problem solving.",
        problems: [
            "Number of 1 Bits"
        ],
        category: "bit"
    },
    {
        name: "Heap",
        icon: "fas fa-layer-group",
        description: "Master heap data structure and priority queue applications.",
        problems: [
            "K Closest Points to Origin",
            "Merge K Sorted Lists",
            "Top K Frequent Elements"
        ],
        category: "heap"
    },
    {
        name: "Tries",
        icon: "fas fa-tree",
        description: "Learn trie data structure and its applications in string problems.",
        problems: [
            "Maximum XOR of Two Numbers in Array"
        ],
        category: "tries"
    }
];

// DOM Elements
const topicsGrid = document.getElementById('topicsGrid');
const loading = document.getElementById('loading');
const searchInput = document.getElementById('searchInput');
const filterButtons = document.querySelectorAll('.filter-btn');
const totalTopics = document.getElementById('totalTopics');
const totalProblems = document.getElementById('totalProblems');

// State
let filteredTopics = [...topicsData];
let currentFilter = 'all';

// Initialize the application
document.addEventListener('DOMContentLoaded', function() {
    setTimeout(() => {
        loading.style.display = 'none';
        renderTopics();
        updateStats();
        setupModalEvents();
    }, 1000);
});

// Setup modal event listeners
function setupModalEvents() {
    const modal = document.getElementById('problemModal');
    const closeBtn = document.querySelector('.close');
    
    // Close modal when clicking X
    closeBtn.addEventListener('click', () => {
        modal.style.display = 'none';
    });
    
    // Close modal when clicking outside
    window.addEventListener('click', (event) => {
        if (event.target === modal) {
            modal.style.display = 'none';
        }
    });
    
    // Close modal with Escape key
    document.addEventListener('keydown', (event) => {
        if (event.key === 'Escape' && modal.style.display === 'block') {
            modal.style.display = 'none';
        }
    });
}

// Render topics
function renderTopics() {
    topicsGrid.innerHTML = '';
    
    filteredTopics.forEach(topic => {
        const topicCard = createTopicCard(topic);
        topicsGrid.appendChild(topicCard);
    });
}

// Create topic card
function createTopicCard(topic) {
    const card = document.createElement('div');
    card.className = 'topic-card';
    card.setAttribute('data-category', topic.category);
    
    const iconClass = getIconClass(topic.category);
    
    card.innerHTML = `
        <div class="topic-header">
            <div class="topic-icon ${topic.category}">
                <i class="${iconClass}"></i>
            </div>
            <h3 class="topic-title">${topic.name}</h3>
        </div>
        <p class="topic-description">${topic.description}</p>
        <div class="topic-stats">
            <div class="problem-count">
                <i class="fas fa-code"></i>
                <span>${topic.problems.length} Problems</span>
            </div>
            <div class="languages">
                <span class="language-badge">Python</span>
                <span class="language-badge">Java</span>
                <span class="language-badge">C++</span>
            </div>
        </div>
    `;
    
    // Add click event to navigate to topic
    card.addEventListener('click', () => {
        navigateToTopic(topic.name);
    });
    
    return card;
}

// Get icon class for category
function getIconClass(category) {
    const iconMap = {
        'arrays': 'fas fa-list',
        'binary': 'fas fa-search',
        'trees': 'fas fa-sitemap',
        'dp': 'fas fa-project-diagram',
        'graphs': 'fas fa-project-diagram',
        'strings': 'fas fa-font',
        'linked': 'fas fa-link',
        'stack': 'fas fa-layer-group',
        'sorting': 'fas fa-sort',
        'hashing': 'fas fa-key',
        'pointers': 'fas fa-hand-point-up',
        'sliding': 'fas fa-window-maximize',
        'greedy': 'fas fa-bullseye',
        'recursion': 'fas fa-undo',
        'matrix': 'fas fa-th',
        'math': 'fas fa-calculator',
        'bit': 'fas fa-microchip',
        'heap': 'fas fa-layer-group',
        'tries': 'fas fa-tree'
    };
    return iconMap[category] || 'fas fa-code';
}

// Show problems modal for a topic
function navigateToTopic(topicName) {
    const topic = topicsData.find(t => t.name === topicName);
    if (!topic) return;
    
    // Update modal title
    document.getElementById('modalTitle').textContent = `${topicName} Problems`;
    
    // Clear and populate problems list
    const problemsList = document.getElementById('problemsList');
    problemsList.innerHTML = '';
    
    topic.problems.forEach(problem => {
        const problemCard = document.createElement('div');
        problemCard.className = 'problem-card';
        
        problemCard.innerHTML = `
            <div class="problem-title">${problem}</div>
            <div class="problem-languages">
                <span class="language-tag python">Python</span>
                <span class="language-tag java">Java</span>
                <span class="language-tag cpp">C++</span>
            </div>
        `;
        
        // Add click event to navigate to specific problem
        problemCard.addEventListener('click', () => {
            navigateToProblem(topicName, problem);
        });
        
        problemsList.appendChild(problemCard);
    });
    
    // Show modal
    document.getElementById('problemModal').style.display = 'block';
}

// Navigate to specific problem
function navigateToProblem(topicName, problemName) {
    // Map display names to actual folder names
    const folderMap = {
        'Arrays': 'Arrays',
        'Binary Search': 'Binary Search',
        'Binary Trees': 'Binary Trees',
        'Dynamic Programming': 'Dynamic Programming',
        'Graphs': 'Graphs',
        'Strings': 'Strings',
        'Linked Lists': 'Linked Lists',
        'Stack and Queue': 'Stack and Queue',
        'Sorting': 'Sorting',
        'Hashing': 'Hashing',
        'Two Pointers': 'Two Pointers',
        'Sliding Window': 'Sliding Window',
        'Greedy': 'Greedy',
        'Recursion and Backtracking': 'Recursion and Backtracking',
        'Matrix': 'Matrix',
        'Math': 'Math',
        'Bit Manipulation': 'Bit Manipulation',
        'Heap': 'Heap',
        'Tries': 'Tries'
    };
    
    const folderName = folderMap[topicName] || topicName.replace(/\s+/g, '_');
    const problemFolder = problemName.replace(/\s+/g, '_').replace(/[^\w\s-]/g, '');
    const url = `./${folderName}/${problemFolder}/`;
    
    // Close modal first
    document.getElementById('problemModal').style.display = 'none';
    
    // Navigate to problem
    const link = document.createElement('a');
    link.href = url;
    link.target = '_blank';
    link.click();
}

// Update statistics
function updateStats() {
    totalTopics.textContent = topicsData.length;
    const totalProblemsCount = topicsData.reduce((sum, topic) => sum + topic.problems.length, 0);
    totalProblems.textContent = totalProblemsCount;
}

// Search functionality
searchInput.addEventListener('input', function() {
    const searchTerm = this.value.toLowerCase();
    
    filteredTopics = topicsData.filter(topic => {
        const matchesSearch = topic.name.toLowerCase().includes(searchTerm) ||
                            topic.description.toLowerCase().includes(searchTerm) ||
                            topic.problems.some(problem => 
                                problem.toLowerCase().includes(searchTerm)
                            );
        
        const matchesFilter = currentFilter === 'all' || topic.category === currentFilter;
        
        return matchesSearch && matchesFilter;
    });
    
    renderTopics();
});

// Filter functionality
filterButtons.forEach(button => {
    button.addEventListener('click', function() {
        // Update active button
        filterButtons.forEach(btn => btn.classList.remove('active'));
        this.classList.add('active');
        
        // Update current filter
        currentFilter = this.getAttribute('data-filter');
        
        // Filter topics
        const searchTerm = searchInput.value.toLowerCase();
        
        filteredTopics = topicsData.filter(topic => {
            const matchesSearch = topic.name.toLowerCase().includes(searchTerm) ||
                                topic.description.toLowerCase().includes(searchTerm) ||
                                topic.problems.some(problem => 
                                    problem.toLowerCase().includes(searchTerm)
                                );
            
            const matchesFilter = currentFilter === 'all' || topic.category === currentFilter;
            
            return matchesSearch && matchesFilter;
        });
        
        renderTopics();
    });
});

// Add smooth scrolling for better UX
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();
        document.querySelector(this.getAttribute('href')).scrollIntoView({
            behavior: 'smooth'
        });
    });
});

// Add loading animation
function showLoading() {
    loading.style.display = 'block';
    topicsGrid.innerHTML = '';
}

function hideLoading() {
    loading.style.display = 'none';
}

// Add keyboard navigation
document.addEventListener('keydown', function(e) {
    if (e.key === 'Escape') {
        searchInput.value = '';
        searchInput.dispatchEvent(new Event('input'));
    }
});

// Add intersection observer for animations
const observerOptions = {
    threshold: 0.1,
    rootMargin: '0px 0px -50px 0px'
};

const observer = new IntersectionObserver(function(entries) {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            entry.target.style.opacity = '1';
            entry.target.style.transform = 'translateY(0)';
        }
    });
}, observerOptions);

// Observe topic cards for animation
document.addEventListener('DOMContentLoaded', function() {
    setTimeout(() => {
        document.querySelectorAll('.topic-card').forEach(card => {
            card.style.opacity = '0';
            card.style.transform = 'translateY(20px)';
            card.style.transition = 'opacity 0.6s ease, transform 0.6s ease';
            observer.observe(card);
        });
    }, 100);
});
