class Solution:
    def merge(self, intervals):
        result = []
        for interval in intervals:
            successfully_merged = False
            for i in range(len(result)):
                existing_interval_start, existing_interval_end = result[i][0], result[i][1]
                input_interval_start, input_interval_end = interval[0], interval[1]
                new_interval_start, new_interval_end = -1, -1
                if input_interval_end < existing_interval_start:
                    pass
                elif input_interval_end >= existing_interval_start and input_interval_end <= existing_interval_end:
                    new_interval_end = existing_interval_end
                    if input_interval_start <= existing_interval_start:
                        new_interval_start = input_interval_start
                    else:
                        new_interval_start = existing_interval_start
                    successfully_merged = True
                elif input_interval_start <= existing_interval_end:
                    new_interval_end = input_interval_end
                    if input_interval_start <= existing_interval_start:
                        new_interval_start = input_interval_start
                    else:
                        new_interval_start = existing_interval_start
                    successfully_merged = True
                else:
                    pass

                if successfully_merged:
                    result[i] = [new_interval_start, new_interval_end]
                    break
            
            if not successfully_merged:
                result.append(interval)
        
        return result