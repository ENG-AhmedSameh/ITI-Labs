package jets.iti.java;
class TestDictionary{
    public static void main(String[] args) {
        String[] allWords = {
                "Apple", "Amazing", "Adventure", "Astounding", "Amiable",
                "Beautiful", "Blissful", "Brave", "Brilliant", "Blossom",
                "Captivating", "Charming", "Creative", "Curious", "Cheerful",
                "Delightful", "Dazzling", "Dynamic", "Dreamy", "Determined",
                "Enchanting", "Energetic", "Elegant", "Expressive", "Exciting",
                "Fantastic", "Friendly", "Fun", "Fresh", "Flourishing",
                "Graceful", "Genuine", "Glorious", "Gifted", "Grateful",
                "Happy", "Harmonious", "Hopeful", "Heartwarming", "Humble",
                "Inspiring", "Incredible", "Imaginative", "Intrepid", "Intelligent",
                "Joyful", "Jovial", "Jubilant", "Jocular", "Jazzy",
                "Kind", "Knowledgeable", "Keen", "Kooky", "Kickass",
                "Lively", "Loving", "Luminous", "Laughter", "Loyal",
                "Magnificent", "Marvelous", "Motivated", "Magical", "Mindful",
                "Nurturing", "Nice", "Nonchalant", "Noble", "Nimble",
                "Optimistic", "Outstanding", "Open-minded", "Original", "Overjoyed",
                "Positive", "Playful", "Passionate", "Polite", "Powerful",
                "Quaint", "Quick-witted", "Quality", "Quiet", "Quizzical",
                "Radiant", "Resilient", "Respectful", "Romantic", "Ready",
                "Serene", "Spirited", "Sincere", "Strong", "Silly",
                "Thankful", "Talented", "Tenacious", "Trustworthy", "Thoughtful",
                "Unique", "Upbeat", "Understanding", "Uplifting", "Unstoppable",
                "Vibrant", "Victorious", "Vivacious", "Valiant", "Versatile",
                "Wonderful", "Warmhearted", "Wise", "Witty", "Wholesome",
                "Xenial", "X-factor", "Xanadu", "Xylophone", "X-ray",
                "Youthful", "Yielding", "Yummy", "Yearning", "Yielding",
                "Zealous", "Zesty", "Zen", "Zippy", "Zany"};
        Dictionary myDictionary = new Dictionary(allWords);
        myDictionary.addWord("Ahmed");
        myDictionary.addWord("Sameh");
        myDictionary.printDictionary();
        myDictionary.getWordsOfChar('x');
    }
}
